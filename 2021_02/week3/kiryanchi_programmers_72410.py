# 코드명: Algostudy 2021 프로그래머스 level 1 (score: 100/ 100)
# 점수
#   정확성: 100
# 작성자: 박기현
# 시작일: 2021-02-07
# 종료일: 2021-02-07
# 코멘트: 정규표현식을 연습할 수 있는 좋은 기회였다.
#         조금 더 정규표현식을 연습해야할 필요가 느껴졌다.
import re


def solution(old_id):
    new_id = old_id.lower()
    new_id = re.sub('[^a-z0-9\-_.]', '', new_id)
    new_id = re.sub('\.+', '.', new_id)
    new_id = re.sub('^\.', '', new_id)
    new_id = re.sub('\.$', '', new_id)
    if new_id == '':
        new_id = 'a'
    if len(new_id) >= 16:
        new_id = new_id[:15]
    if new_id[-1] == '.':
        new_id = new_id[:-1]
    if len(new_id) <= 2:
        while len(new_id) < 3:
            new_id += new_id[-1]
    return new_id
