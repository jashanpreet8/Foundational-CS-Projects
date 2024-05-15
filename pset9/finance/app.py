import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]

    trans_db = db.execute('SELECT symbol, name, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol', user_id)

    cash_db = db.execute('SELECT cash FROM users WHERE id = ?', user_id)
    cash = cash_db[0]['cash']

    return  render_template("index.html", database = trans_db, cash = cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")

    else:
        symbol = request.form.get('symbol')
        if not symbol or symbol == '' or lookup(symbol)['symbol'] == None:
            return apology('Enter symbol/symbol does not exist', 403)

        shares = int(request.form.get('shares'))
        if not shares or shares <= 0:
            return apology('Enter valid value', 403)

        user_id = session["user_id"]
        price = lookup(symbol)['price']
        cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = cash_db[0]["cash"]

        name = lookup(symbol)['name']

        total_stock = price * shares
        if total_stock > cash:
            return apology('Insufficient funds', 403)

        updt_cash = cash - total_stock
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        date = datetime.datetime.now()
        db.execute("INSERT INTO transactions (user_id, symbol, name, shares, price, date) VALUES (?, ?, ?, ?, ?, ?)", user_id, symbol, name, shares, price, date)

        db.execute("INSERT INTO history (purchase_or_sale, symbol, price, shares, date, user_id) VALUES ('purchase', ?, ?, ?, ?, ?)", symbol, price, shares, date, user_id)

        flash('Bought!')

        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session['user_id']
    hist_db = db.execute('SELECT purchase_or_sale, symbol, price, shares, date FROM history WHERE user_id = ?', user_id)
    return render_template('history.html', data=hist_db)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")

    if not request.form.get('symbol'):
        return apology("Must input stock's symbol", 403)

    info = lookup(request.form.get('symbol'))

    if request.method == "POST":
        return render_template("quoted.html", info=info)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    session.clear()

    if request.method == "POST":
        if not request.form.get('username'):
            return apology('Must provide username', 403)

        check = db.execute("SELECT * FROM users WHERE username = ?", request.form.get('username'))
        if len(check) >= 1:
            return apology('Username already exists', 403)

        if not request.form.get('password') or not request.form.get('confirmation'):
            return apology('Must provide password', 403)

        if request.form.get('password') != request.form.get('confirmation'):
            return apology('Passwords do not match', 403)

        uname = request.form.get('username')
        pword = generate_password_hash(request.form.get('password'))
        db.execute("INSERT INTO USERS (username, hash) VALUES(?, ?)", uname, pword)

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session['user_id']

    if request.method == "GET":
        stocks = []
        stock_names = db.execute("SELECT name from transactions WHERE user_id = ? GROUP BY name", user_id)
        for row in stock_names:
            stocks.append(row['name'])

        return render_template("sell.html", stocks=stocks)

    else:
        symbol = request.form.get('symbol')
        share = request.form.get('shares')

        shares_db = db.execute("SELECT shares FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol", user_id, symbol)[0]["shares"]
        price = lookup(symbol)['price']

        if not symbol or not share:
            return apology('Fill all fields', 403)
        elif share < 0 or share > shares_db:
            return apology('Enter valid shares', 403)
        elif share == shares_db:
            db.execute("DELETE FROM transactions WHERE user_id = ? AND symbol LIKE ? and shares = ?", user_id, symbol, shares_db)
        elif share < shares_db:
            db.execute("UPDATE transactions SET shares = ? WHERE user_id = ?", (shares_db - share), user_id)

        cash_real = ('SELECT cash FROM users WHERE id = ?', user_id)[0]["cash"]
        updt_cash = price*share
        db.execute('UPDATE users SET cash = ? WHERE id = ?', (cash_real + updt_cash), user_id)

        date = datetime.datetime.now()

        db.execute("INSERT INTO history (purchase_or_sale, symbol, price, shares, date, user_id) VALUES ('sale', ?, ?, ?, ?, ?)", symbol, price, share, date, user_id)

        flash('Sold!')

        return redirect('/')

