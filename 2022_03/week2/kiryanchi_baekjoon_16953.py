import sys

def solve(A, B):
    cnt = 0
    tmp = B
    while True:
        if tmp % 2 == 0:
            tmp //= 2
            cnt += 1
        elif tmp % 10 == 1:
            tmp //= 10
            cnt += 1
        else:
            return -1

        if tmp <= A:
            break

    if tmp == A:
        return cnt + 1
    return -1
        

A, B = map(int, sys.stdin.readline().strip().split())

result = solve(A, B)
print(result)
