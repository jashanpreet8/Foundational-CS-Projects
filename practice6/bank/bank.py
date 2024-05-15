s = input('Greeting: ')

s = s.lower().strip()

if 'hello' in s:
    print('$0')
elif s[0] == 'h':
    print('$20')
else:
    print('$100')