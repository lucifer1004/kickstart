t = int(input())
for case_num in range(1, t + 1):
    n, d = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    l = 1
    r = d
    while l <= r:
        mid = (l + r) // 2
        day = mid
        for x in a:
            day = ((day - 1) // x + 1) * x
        if day > d:
            r = mid - 1
        else:
            l = mid + 1
    print('Case #{}: {}'.format(case_num, r))
