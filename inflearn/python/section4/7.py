# 창고 정리
l = int(input())

heights = list(map(int, input().split()))

m = int(input())

for _ in range(m):
    heights.sort()

    heights[0] += 1
    heights[-1] -= 1

heights.sort()

print(heights[-1] - heights[0])
