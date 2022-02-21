import re

line = input()
numbers = re.split('[+-]', line)
number = map(int, numbers)

isMinus = False
sum = 0
idx = 0

for c in line:
    if c in '+-':
        sum = sum + numbers[idx]
        

print(numbers)
