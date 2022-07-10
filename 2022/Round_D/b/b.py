from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


def solve(a):
    n = len(a)
    ans = [0] * (n + 1)
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        ndp = [0] * (n + 1)
        for j in range(i):
            ndp[j] = max(ndp[j], dp[j] + a[n - i + j])
            ndp[j + 1] = max(ndp[j + 1], dp[j] + a[j])
        dp = ndp
        ans[i] = max(dp)
    return ans


t = read_int()
for case_num in range(1, t + 1):
    n = read_int()
    a = list(read_ints())
    m = read_int()
    b = list(read_ints())
    k = read_int()
    sa = solve(a)
    sb = solve(b)
    ans = 0
    for ca in range(n + 1):
        cb = k - ca
        if cb > m:
            continue
        if cb < 0:
            break
        ans = max(ans, sa[ca] + sb[cb])
    print(f'Case #{case_num}: {ans}')
