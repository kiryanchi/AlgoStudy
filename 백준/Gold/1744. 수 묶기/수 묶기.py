def calc_nums_sum(n_list):
    """
    앞에서부터 수를 곱해서 더해주는 함수
    """
    flag = False
    sum = 0
    tmp = 0
    for n in n_list:
        if flag:
            flag = False
            if n == 1:
                sum += tmp + n
            else:
                sum += tmp * n
        else:
            flag = True
            tmp = n
    if len(n_list) % 2 == 1:
        sum += tmp
    return sum


def main():
    N = int(input())
    pnums = []
    nnums = []
    for _ in range(N):
        n = int(input())
        if n <= 0:
            nnums.append(n)
        else:
            pnums.append(n)
    nnums.sort()
    pnums.sort(reverse=True)

    p_sum = calc_nums_sum(pnums)
    n_sum = calc_nums_sum(nnums)

    print(p_sum + n_sum)


main()
