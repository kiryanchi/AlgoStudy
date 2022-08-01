n = int(input())

cnt = 0

while n != 1:
    if n % 3 == 0:
        cnt += 1
        n = n // 3
    elif n % 2 == 0:
        cnt += 1
        n = n // 2
    else:
        cnt += 1
        n -= 1

    print(n)

print(cnt)
