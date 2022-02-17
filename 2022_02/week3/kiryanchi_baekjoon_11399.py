N = int(input())
P = list(map(int, input().split()))

P = sorted(P)
sum = 0

for p in P:
    sum += p * N
    N -= 1

print(sum)
