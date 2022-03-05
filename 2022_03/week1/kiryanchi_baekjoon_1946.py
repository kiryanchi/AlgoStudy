import sys

N = int(input())
for i in range(N):
    T = int(input())
    scores = []
    for j in range(T):
        score = list(map(int, sys.stdin.readline().split()))
        scores.append(score)
    scores.sort()
    max2 = 9999999
    pass_people = T
    for first, second in scores:
        if second > max2:
            pass_people -= 1
        else:
            max2 = second
    print(pass_people)
