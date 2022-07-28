N, M = map(int, input().split())

sum = 0
x6 = 99999999
x = 99999999

for i in range(M):
    tmp6, tmp = map(int, input().split())

    if tmp6 < x6:
        x6 = tmp6

    if tmp < x:
        x = tmp

if x6 > x * 6:
    x6 = x * 6

while N > 6:
    sum += x6
    N -= 6

if N * x > x6:
    sum += x6
else:
    sum += N * x

print(sum)
