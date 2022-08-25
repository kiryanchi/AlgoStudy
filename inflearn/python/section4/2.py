k, n = map(int, input().split())

cables = []

for _ in range(k):
    cables.append(int(input()))

cables.sort()

result = 0

left = 1
right = cables[-1]

while left <= right:
    mid = (left + right) // 2
    cnt = 0

    for cable in cables:
        cnt += cable // mid

    if cnt < n:
        right = mid - 1

    elif cnt >= n:
        result = mid
        left = mid + 1
print(result)
