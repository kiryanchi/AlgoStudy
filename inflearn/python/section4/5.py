def run():
    n = int(input())

    times = []
    cnt = 1

    for _ in range(n):
        times.append(list(map(int, input().split())))

    times.sort(key=lambda x: x[1])

    end_time = times[0][1]
    for time in times:
        if time[0] == end_time:
            end_time = time[1]
            cnt += 1

    print(cnt)


if __name__ == "__main__":
    run()
