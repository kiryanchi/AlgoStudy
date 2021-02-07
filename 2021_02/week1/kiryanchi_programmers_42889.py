# 코드명: Algostudy 2021 프로그래머스 level 1 (score: 100/ 100)
# 점수
#   정확성: 71.9
#   효율성: 28.1
# 작성자: 박기현
# 시작일: 2021-02-06
# 종료일: 2021-02-06
# 코멘트: 쉽다 쉬워

def solution(arr):
    answer = []
    temp = -1
    for i in arr:
        if temp != i:
            temp = i
            answer.append(temp)
    return answer
