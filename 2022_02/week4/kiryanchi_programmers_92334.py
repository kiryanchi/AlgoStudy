# 프로그래머스 2022 KAKAO BLIND RECRUITMENT 신고 결과 받기
# 2022/02/21
'''
    배워야할 점
        1. set()
        2. list.index()
'''
def solution(id_list, report, k):
    answer = []
    reportedUser = {}
    receiveMail = {}
    for id in id_list:
        reportedUser[id] = set()
        receiveMail[id] = 0
        
    for rep in report:
        a, b = rep.split()
        reportedUser[b].add(a)
    # print(reportedUser)
    
    for val in reportedUser.values():
        # val: set
        if len(val) >= k:
            for user in val:
                receiveMail[user] += 1
            
    # print(list(receiveMail.values()))
    answer = list(receiveMail.values())
    return answer
