-- Keep a log of any SQL queries you execute as you solve the mystery.

--get description from the time of theft
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
--get transcripts of 3 witnesses
select * from interviews where month = 7 and day = 28;
--follow ruth's lead to get license_plate
select * from bakery_security_logs where year = 2021 and month = 7 and day = 28 and hour = 10 and minute > 15 and minute < 25;
--check bank accounts for names with eugene's lead
select * from people
join bank_accounts on bank_accounts.person_id = people.id
join atm_transactions on atm_transactions.account_number = bank_accounts.account_number
where atm_transactions.month = 7 and atm_transactions.day = 28 and atm_transactions.atm_location = 'Leggett Street'
and atm_transactions.transaction_type = 'withdraw';
--follow raymond's lead
select * from phone_calls where year = 2021 and month = 7 and day = 28 and duration < 60;
--check airports in fiftyville and after getting airport name check for flights as raymond mentioned thief will take early flight the next day
select * from flights where year = 2021 and month = 7 and day = 29 and origin_airport_id in (select id from airports where city = 'Fiftyville');
--check airport names with received ids
select * from airports where id = 4 or id = 9;
--cross-refernced ruth and raymond and eugene's leads, 2 suspects = bruce, diana
--get info about who they both called in bakery
select * from people where phone_number like '(375) 555-8161' or phone_number like '(725) 555-3243';
--get passenger details for flights and check passport number of bruce, diana, robin, philip
select * from passengers
join people on people.passport_number = passengers.passport_number
where (passengers.flight_id = 36 or passengers.flight_id = 43) and (people.name = 'Bruce' or people.name = 'Diana'
or people.name = 'Robin' or people.name = 'Philip');