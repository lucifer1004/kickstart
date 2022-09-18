from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    n = read_int()
    fabrics = []
    for _ in range(n):
        C, D, U = input().split()
        D, U = int(D), int(U)
        fabrics.append((C, D, U))
    ada = sorted(fabrics, key=lambda x: (x[0], x[2]))
    charles = sorted(fabrics, key=lambda x: (x[1], x[2]))
    print(
        f'Case #{case_num}: {len([i for i in range(n) if ada[i] == charles[i]])}')
