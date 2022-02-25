'''
    - 가 나오면 그 뒤의 덧셈을 다 해서 빼준다는 접근은 맞았지만,
    좀 더 간단한 방법이 있었다.
    split을 해줄 때, - 단위로 구분하고 그 다음 +로 뭉쳐있는 식을 다 더해서 빼주면 내가 생각한 방법을 그대로 구현할 수 있었다.
'''
'''import re

SIGN = "+-"

line = input()
numbers = re.split("[+-]", line)
number = list(map(int, numbers))
giho = []
isMinus = False
sum = number[0]
idx = 1

for c in line:
    if c in SIGN:
        giho.append(c)


for g in giho:
    if not isMinus:
        if g == '+':
            sum = sum + number[idx]
        else:
            sum = sum - number[idx]
            isMinus = True
    else:
        if g == '+':
            sum = sum - number[idx]
        else:
            sum = sum - number[idx]
            isMinus = False
    idx += 1

print(sum)
'''
temp = []
sum = 0
line = input()
for expr in line.split('-'):
    for e in expr.split('+'):
        sum += int(e)
    temp.append(sum)
    sum = 0

sum = temp[0]
for t in temp[1:]:
    sum -= t
print(sum)
