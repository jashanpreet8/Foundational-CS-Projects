import csv
from cs50 import SQL

def create_house(house, houses, head):
    count = 0
    for h in houses:
        if h["house"] == house:
            count += 1
    if count == 0:
        houses.append({"house" : house, "head" : head})

def create_student(name, dstudents):
    dstudents.append({"student_name" : name})

def house_assigns(name, house, house_assign):
    house_assign.append({"student_name" : name, "house" : house})

db = SQL("sqlite:///roster.db")

dstudents = []
houses = []
house_assign = []

with open("students.csv") as csv_file:
    reader = csv.DictReader(csv_file)
    for row in reader:
        name = row["student_name"]
        house = row["house"]
        head = row["head"]

        create_house(house, houses, head)
        create_student(name, dstudents)
        house_assigns(name, house, house_assign)

for student in dstudents:
    db.execute("INSERT INTO students (student_name) VALUES (?)", student["student_name"])

for ass in house_assign:
    db.execute("INSERT INTO house_assign (student_name, house) VALUES (?, ?)", ass["student_name"], ass["house"])

for ho in houses:
    db.execute("INSERT INTO houses (house, head) VALUES (?, ?)", ho["house"], ho["head"])
