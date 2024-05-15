import re

while True:
    card = int(input('Number: '))
    if card > 0:
        break

card1 = int((((card % 100)/10)*2))
card2 = int((((card % 10000)/1000)*2))
card3 = int((((card % 1000000)/100000)*2))
card4 = int((((card % 100000000)/10000000)*2))
card5 = int((((card % 10000000000)/1000000000)*2))
card6 = int((((card % 1000000000000)/100000000000)*2))
card7 = int((((card % 100000000000000)/10000000000000)*2))
card8 = int((((card % 10000000000000000)/1000000000000000)*2))

card1 = int(((card1 % 100)/10)) + int((card1 % 10))
card2 = int(((card2 % 100)/10)) + int((card2 % 10))
card3 = int(((card3 % 100)/10)) + int((card3 % 10))
card4 = int(((card4 % 100)/10)) + int((card4 % 10))
card5 = int(((card5 % 100)/10)) + int((card5 % 10))
card6 = int(((card6 % 100)/10)) + int((card6 % 10))
card7 = int(((card7 % 100)/10)) + int((card7 % 10))
card8 = int(((card8 % 100)/10)) + int((card8 % 10))

sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8

card9 = int((card % 10))
card10 = int(((card % 1000)/100))
card11 = int(((card % 100000)/10000))
card12 = int(((card % 10000000)/1000000))
card13 = int(((card % 1000000000)/100000000))
card14 = int(((card % 100000000000)/10000000000))
card15 = int(((card % 10000000000000)/1000000000000))
card16 = int(((card % 1000000000000000)/100000000000000))

sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16

sum3 = sum1 + sum2

if(sum3 % 10 != 0):
    x = False
else:
    x = True

card = str(card)

if x and len(card) == 15 and re.search('^34|^37', card):
    print('AMEX')

elif x and len(card) == 16 and re.search('^51|^52|^52|^53|^54|^55', card):
    print('MASTER')

elif x and (len(card) == 13 or len(card) == 16) and re.search('^4', card):
    print('VISA')

else:
    print('INVALID')

'''
def validity(card):
    sum1 = 0
    sum2 = 0
    if len(card) == 16:
        for i in range(0, len(card), 2):
            card[i] = card[i])
            p = card[i] * 2
            p = str(p)
            if len(p) == 1:
                p = p)
                sum1 += p
            elif len(p) > 1:
                for y in range(len(p)):
                    p[y] = p[y])
                    sum1 += p[y]
        for i in range(1, len(card), 2):
            card = card)
            sum2 += card[i]

    elif len(card) == 13 or len(card) == 15:
        for i in range(1, len(card), 2):
            card[i] = card[i])
            p = card[i] * 2
            p = str(p)
            if len(p) == 1:
                p = p)
                sum1 += p
            elif len(p) > 1:
                for y in range(len(p)):
                    p[y] = p[y])
                    sum1 += p[y]
        for i in range(0, len(card), 2):
            card = card)
            sum2 += card[i]

    else:
        return False

    sum = sum1 + sum2
    if sum % 10 == 0:
        return True
    else:
        return False
'''