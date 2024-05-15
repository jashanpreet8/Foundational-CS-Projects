while True:
    try:
        height = int(input('Height: '))
        if height > 0 and height < 8:
            break
    except ValueError:
        print('Not an integer.')

for i in range(height):
    for j in range(height-i-1):
        print(' ', end='')
    for k in range(i+1):
        print('#', end='')
    print()