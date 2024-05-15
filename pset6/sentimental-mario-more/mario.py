while True:
    try:
        height = int(input('Height: '))
        if height > 0 and height < 9:
            break
    except ValueError:
        print('Not an integer.')

for i in range(height):
    for j in range(height-i-1):
        print(' ',end='')
    for k in range(i+1):
        print('#', end='')
    #for x in range(0, height, height):
    print('  ', end='')
    for y in range(i+1):
        print('#', end='')
    print()