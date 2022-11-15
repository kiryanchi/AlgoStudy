from collections import deque


def DFS(start):
    global cnt, visited
    visited[start] = 1
    for point in graph[start]:
        if visited[point] == 0:
            DFS(point)
            cnt += 1


if __name__ == "__main__":
    n = int(input())
    graph = {}
    stack = deque()
    visited = [0 for _ in range(n + 1)]
    cnt = 0

    # 그래프 초기화
    for i in range(1, n + 1):
        graph[i] = deque()

    for _ in range(int(input())):
        f, s = map(int, input().split())
        graph[f].append(s)
        graph[s].append(f)

    # 1번 컴퓨터부터 감염 시작
    DFS(1)

    print(cnt)