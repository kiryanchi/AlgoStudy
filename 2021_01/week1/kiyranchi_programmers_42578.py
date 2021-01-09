# 코드명 : AlgoStudy 2021 프로그래머스 해시 level 2 (score : 100/100)
# 작성자 : 박기현
# 문제명 : 위장
# 시작일 : 2021-01-09
# 종료일 : 2021-01-09

def solution(clothes):
    answer = 1
    hash = {}
    # hash 딕셔너리안에 옷 종류를 키로 만듬
    for clothe in clothes:
        if clothe[1] in hash:
            hash[clothe[1]] += 1
        else:
            hash[clothe[1]] = 1
    
    # 옷의 개수 + 옷을 입지 않는 경우 해서 + 1 을 해줌
    for num_of_clothes in hash.values():
        answer *= (num_of_clothes + 1)
    
    # 옷을 전부 입지 않는 경우는 없으므로 1개를 빼준다.
    return asnwer - 1

# 소감
#
# dictionary를 사용해서 옷의 개수를 저장하는 접근까지는 맞았지만 컴비네이션을 사용해서 풀려고했다. 옷을 입지 않는 경우를 왜 생각을 못 했을까..