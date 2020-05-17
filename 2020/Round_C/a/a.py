def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(1, t+1):
    n, k = read_ints()
    a = list(read_ints())
    idx = []
    for i in range(n):
        if a[i] == 1:
            idx.append(i)
    ans = 0
    for i in idx:
        if i < k - 1:
            continue
        ok = True
        for j in range(1, k):
            if a[i - j] != j + 1:
                ok = False
                break
        if ok:
            ans += 1
    print('Case #{}: {}'.format(case_num, ans))
