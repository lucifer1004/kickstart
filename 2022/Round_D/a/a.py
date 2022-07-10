from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    n, m = read_ints()
    a = list(read_ints())
    a.sort()
    rem = n - m + 1
    ans = sum(a[rem:]) + ((a[rem // 2 - 1] + a[rem // 2]) /
                          2 if rem % 2 == 0 else a[rem // 2])
    print(f'Case #{case_num}: {ans:.1f}')
