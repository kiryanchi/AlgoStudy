import sys

from collections import deque

input = sys.stdin.readline

dx = (-1, 0, 1, 0)
dy = (0, -1, 0, 1)


def DFS(i, j):
    global home_cnt
    if _map[i][j] != 1:
        return

    _map[i][j] = 2
    home_cnt += 1
    # 상하좌우
    for k in range(4):
        # 올바른 index
        next_i = i + dx[k]
        next_j = j + dy[k]
        if 0 <= next_i < n and 0 <= next_j < n:
            DFS(i + dx[k], j + dy[k])


if __name__ == "__main__":
    n = int(input().rstrip())

    _map = []

    result = []

    for _ in range(n):
        line = []
        for c in input().rstrip():
            line.append(int(c))
        _map.append(line)

    for i in range(n):
        for j in range(n):
            if _map[i][j] == 1:
                home_cnt = 0
                DFS(i, j)
                result.append(home_cnt)

    result.sort()
    print(len(result))
    for r in result:
        print(r)
