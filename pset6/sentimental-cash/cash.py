from cs50 import get_float

def main():
    while True:
        try:
            cash = get_float('Change owed: ')
            if cash > 0:
                break
        except ValueError:
            print('Not an integer.')

    cash = int(cash*100)

    quarters = calc_quarters(cash)
    cash = cash - quarters*25

    dimes = calc_dimes(cash)
    cash = cash - dimes*10

    nickels = calc_nickels(cash)
    cash = cash - nickels*5

    pennies = calc_pennies(cash)
    cash = cash - pennies*1

    sum = quarters + dimes + nickels + pennies
    print(sum)

def calc_quarters(cash):
    if cash >= 25:
        rem = cash % 25
        cash = (cash - rem) / 25
        return cash
    else:
        return 0

def calc_dimes(cash):
    if cash >= 10:
        rem = cash % 10
        cash = (cash - rem) / 10
        return cash
    else:
        return 0

def calc_nickels(cash):
    if cash >= 5:
        rem = cash % 5
        cash = (cash - rem) / 5
        return cash
    else:
        return 0

def calc_pennies(cash):
    if cash >= 1:
        rem = cash % 1
        cash = (cash - rem) / 1
        return cash
    else:
        return 0


main()