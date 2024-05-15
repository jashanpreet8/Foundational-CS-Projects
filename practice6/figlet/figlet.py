from sys import argv, exit
import random

from pyfiglet import Figlet
figlet = Figlet()

if len(argv) != 1 and len(argv) != 3:
    print('Invalid usage1')
    exit(1)

if len(argv) == 1:
    figlet.getFonts()
    figlet.setFont(font=random.choice(figlet.getFonts()))
    msg = input('Text: ')
    print(figlet.renderText(msg))

if len(argv) == 3:
    if argv[1] != '-f' and argv[1] != '--font':
        print('Invalid usage2')
        exit(1)
    figlet.setFont(font=argv[2])
    if argv[2] not in figlet.getFonts():
        print('Invalid usage3')
        exit(1)
    msg = input('Text: ')
    print(figlet.renderText(msg))