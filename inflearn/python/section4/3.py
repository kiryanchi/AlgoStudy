def count(songs, capacity):
    sum = 0
    cnt = 0
    for song in songs:
        if song > capacity:
            break

        if sum + song > capacity:
            sum = song
            cnt += 1

        else:
            sum += song

    return cnt


def main():
    n, m = map(int, input().split())

    songs = list(map(int, input().split()))

    lt = 0
    rt = 0

    for length in songs:
        rt += length

    result = 0
    while lt <= rt:
        cnt = 0
        sum_len = 0
        mid = (lt + rt) // 2

        for length in songs:
            sum_len += length

            if sum_len > mid:
                sum_len = length
                cnt += 1

            elif sum_len == mid:
                sum_len = 0
                cnt += 1

        if sum_len != 0:
            cnt += 1

        if cnt <= m:
            result = mid
            rt = mid - 1

        elif cnt > m:
            lt = mid + 1

    print(result)


if __name__ == "__main__":
    main()
