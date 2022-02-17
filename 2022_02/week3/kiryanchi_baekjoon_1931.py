def solution(InputArr):
    cnt = 0
    endTime = -1

    for time in InputArr:
        if endTime <= time[0]:
            endTime = time[1]
            cnt += 1
    return cnt

N = int(input())
A = []

for i in range(N):
    A.append(list(map(int, input().split())))
    
A.sort(key=lambda x: (x[1], x[0]))

print(solution(A))
