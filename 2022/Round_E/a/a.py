from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    n = read_int()
    print(f'Case #{case_num}: {(n - 1) // 5 + 1}')
