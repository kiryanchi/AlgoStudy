# 코드명 : AlgoStudy 2021 프로그래머스 해시 level 1 (score : 50/50)
# 작성자 : 박기현
# 문제명 : 완주하지 못 한 선수
# 시작일 : 2021-01-04
# 종료일 : 2021-01-04

def solution(participant, completion):
    participant.sort()
    completion.sort()
    
    for (i, j) in zip(participant, completion)수
        if (i != j):
            return i
    return participant[-1]

# 소감
# 
# 해시를 사용하지 않았다. 해시를 사용하는 좋은 방법은 없을까? 해시에 대한 공부가 좀 더 필요할 것 같다.