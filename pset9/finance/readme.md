# C$50 Finance

C$50 Finance is a web application inspired by real-world stock trading, created to allow users to manage a portfolio of stocks by "buying" and "selling" shares. The project was developed as part of Harvard's CS50x course, with an emphasis on using web development skills, SQL database interactions, and APIs to fetch live stock data. Users can register an account, track their cash balance, view transaction history, and perform operations like buying or selling stocks.

## Features

- **User Registration & Authentication**:
  - New users can create an account with a unique username and password.
  - Authentication is secured through password hashing, and only logged-in users can access portfolio management features.

- **Portfolio Management**:
  - Users receive $10,000 in virtual cash upon account creation.
  - Users can view their current stock holdings, including the number of shares, stock prices, and the total portfolio value.

- **Stock Transactions**:
  - **Buy Stocks**: Users can search for stocks by symbol, view the latest price, and purchase shares if they have sufficient funds.
  - **Sell Stocks**: Users can sell shares of stocks they own, with restrictions based on the number of shares held.
  - **Quote Lookup**: A search feature that allows users to view real-time stock prices.

- **Transaction History**: View a complete history of all purchases and sales made by the user, including the date, stock symbol, and price.

- **Additional Feature**:
  - Users can add extra cash to their account balance to buy more stocks.

## Technologies Used

- **Python (Flask)**: The web framework used to build and manage the backend server and web routes.
- **Jinja**: Used for rendering HTML templates dynamically.
- **SQLite**: Database to store user data, stock transactions, and portfolio details.
- **HTML/CSS (Bootstrap)**: For designing the user interface.
- **JavaScript**: For handling client-side interactions.
- **IEX Cloud API**: Fetches real-time stock prices.
