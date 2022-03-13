import sys

def overlap_del(line):
    result = []

    for i in range(len(line)):
        if i == 0:
            result.append(line[i])
        elif line[i] != result[-1]:
            result.append(line[i])

    return ''.join(result)

S = sys.stdin.readline().strip()

S = ''.join(overlap_del(S))

cnt0, cnt1 = S.count('0'), S.count('1')

cnt = min(cnt0, cnt1)
print(cnt)
