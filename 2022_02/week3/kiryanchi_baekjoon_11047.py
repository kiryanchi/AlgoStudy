N,K = map(int,input().split())
A = []
cnt = 0

for i in range(N):
    A.append(int(input()))

A = sorted(A, reverse=True)
for a in A:
    if K == 0:
        break

    if K // a != 0:
        cnt = cnt + (K // a)
        K %= a

print(cnt)
