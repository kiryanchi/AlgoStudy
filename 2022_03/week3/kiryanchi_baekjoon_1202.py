import sys
from heapq import heappop, heapify

N, K = map(int, sys.stdin.readline().split())
jewels = []
bags = []
sum = 0

for i in range(N):
    jewel = list(map(int, sys.stdin.readline().split()))
    jewel.append(False)
    jewels.append(jewel)

jewels.sort(reverse=True, key=lambda x: x[1])

for i in range(K):
    bags.append(int(sys.stdin.readline()))

heapify(bags)

idx = 0

while len(bags) != 0:
    bag = heappop(bags)
    for jewel in jewels:
        if jewel[2] == True:
            continue
        if jewel[0] <= bag:
            sum += jewel[1]
            jewel[2] = True
            break

print(sum)
