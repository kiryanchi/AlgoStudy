n = int(input())

people = []

for _ in range(n):
    people.append(list(map(int, input().split())))

people.sort(key=lambda x: x[1], reverse=True)

max_height = 0
cnt = 0

for height, _ in people:
    if height > max_height:
        cnt += 1
        max_height = height

print(cnt)
