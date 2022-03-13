import sys

idx = 0

while True:
    idx += 1
    result = 0
    L, P, V = map(int, sys.stdin.readline().strip().split())

    if L == 0:
        break
    
    result += (V // P) * L

    if V % P <= L:
        result += V % P
    else:
        result += L

    print(f'Case {idx}: {result}')
