# 코드명: Algostudy 2021 프로그래머스 level 1 (score: 100/ 100)
# 점수
#   정확성: 100/ 100
# 작성자: 박기현
# 시작일: 2021-02-07
# 종료일: 2021-02-07
# 코멘트: 쉽다 쉬워

def solution(d, budget):
    answer = 0
    d.sort()
    sum_d = 0
    for i in d:
        sum_d += i
        if sum_d <= budget:
            answer += 1
        else:
            break
    return answer
