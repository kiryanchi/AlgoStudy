# 침몰하는 타이타닉(그리디)
from collections import deque

n, m = map(int, input().split())

weights = list(map(int, input().split()))

weights.sort()

weights = deque(weights)

lt = 0
rt = n - 1
cnt = 0

while len(weights) > 0:
    if weights[0] + weights[-1] > m:
        weights.pop()
        cnt += 1
    else:
        weights.popleft()
        weights.pop()
        cnt += 1
print(cnt)
