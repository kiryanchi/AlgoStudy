def main():
    N, L = map(int, input().split())

    spots = list(map(int, input().split()))
    spots.sort()

    taping = True
    start = spots[0]
    cnt = 1
    for spot in spots[1:]:
        if spot - start > L - 1:
            start = spot
            cnt += 1

    print(cnt)


main()
