n, c = map(int, input().split())

X = []

for _ in range(n):
    X.append(int(input()))

X.sort()

lt = 0
rt = X[-1] - X[0]
result = 0

while lt <= rt:
    pos = 0
    cnt = 1
    mid = (lt + rt) // 2

    for i in range(pos, n):
        if cnt == 3:
            break

        if X[i] - X[pos] >= mid:
            pos = i
            cnt += 1

    if cnt < c:
        rt = mid - 1

    elif cnt >= 3:
        result = mid
        lt = mid + 1

print(result)
