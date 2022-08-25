n, m = map(int, input().split())

input_list = list(map(int, input().split()))

input_list.sort()

lt = 0
pos = n // 2
rt = n-1

while lt <= rt:
    mid = (lt + rt) // 2

    if input_list[mid] == m:
        print(mid + 1)
        break
    else:
        if input_list[mid] > m:
            rt = mid - 1
        else:
            lt = mid + 1
