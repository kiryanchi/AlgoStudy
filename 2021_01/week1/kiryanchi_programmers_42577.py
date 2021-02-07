# 코드명 : AlgoStudy 2021 프로그래머스 해시 level 2 (score : 100/100)
# 작성자 : 박기현
# 문제명 : 전화번호 목록
# 시작일 : 2021-01-04
# 종료일 : 2021-01-04

def solution(phone_book):
    answer = True
    hashTable = {}

    # 해시테이블 채우기
    for num in phone_book:
        hashTable[num] = 1

    # 한글자씩 추가해 해시테이블과 비교
    for num in phone_book:
        tmp = ""
        for char in num:
            tmp += char
            if tmp in hashTable and tmp != num:
                answer = False
    return answer

# 소감
#
# 해시를 어거지로 쓴 느낌이라 살짝 아쉽다. 해쉬를 사용하는 다른 좋은 방법은 없을까?

