# 코드명 : AlgoStudy 2022 백준 그리디 2839
# 작성자 : kiryanchi
# 문제명 : 설탕배달
# 시작일 : 2022-02-16
'''
    첫 그리디 알고리즘
    간단한 문제인데도 생각하기가 힘드네
'''

N = int(input())
cnt = 0

# case 1
while N >= 0:
    if N % 5 == 0:
        cnt += N // 5
        break

    N -= 3
    cnt += 1
    
if N < 0:
    cnt = -1
print(cnt)
