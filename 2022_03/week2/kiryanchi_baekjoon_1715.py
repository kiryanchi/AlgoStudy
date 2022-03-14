import sys
import heapq

N = int(sys.stdin.readline())
stack = []
result = 0
tmp = 0

for i in range(N):
    stack.append(int(sys.stdin.readline()))

heapq.heapify(stack)

while len(stack) != 1:
    A, B = heapq.heappop(stack), heapq.heappop(stack)
    tmp = A + B
    result += tmp

    heapq.heappush(stack, tmp)


print(result)
