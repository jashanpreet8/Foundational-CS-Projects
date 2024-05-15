text = input('Text: ')

l = w = s = 0
for i in range(len(text)):
    if text[i].isalpha():
        l += 1
    if text[i].isspace():
        w += 1
    if text[i] == '.' or text[i] == '!' or text[i] =='?':
        s += 1
w += 1
L = l/w * 100.0
S = s/w * 100.0

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print('Before Grade 1')
elif index > 16:
    print('Grade 16+')
else:
    print(f'Grade {index}')