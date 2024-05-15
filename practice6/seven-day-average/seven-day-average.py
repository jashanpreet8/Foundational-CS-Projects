import csv
import requests

def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


#TODO Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    state = reader.state
    day = reader.state.cases
    new_cases= {state: day(14)}
    for i in range[1:14]:
        day[i] = day[i] - day[i-1]
        day[i] = day.append()
    return new_cases



#TODO Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        averagelast = sum(new_cases.day[-7:]) / 7
        averagefirst = sum(new_cases.day[:8]) / 7
        percent = averagelast - averagefirst
        try:
            percent /= averagelast
        except ZeroDivisionError:
            print('zero division error')
        if percent > 0:
            print(f"{state} had a 7-day average of {averagelast} and an increase of {percent}% ")
        if percent < 0:
             print(f"{state} had a 7-day average of {averagelast} and a decrease of {percent}%")


main()
