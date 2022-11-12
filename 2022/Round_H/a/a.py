from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    L, N = read_ints()
    last = 'X'
    pos = 0
    counter = 0
    for _ in range(N):
        D, C = input().split()
        D = int(D)
        if C == 'C':
            if last != 'A' or pos == 0:
                counter += (pos + D) // L
            else:
                counter += max(0, (D - (L - pos)) // L)
            if pos == 0 or pos + D >= L:
                last = C
            pos = (pos + D) % L
        else:
            if last != 'C' or pos == 0:
                counter += ((L - pos) % L + D) // L
            else:
                counter += max(0, (D - pos) // L)
            if D >= pos:
                last = C
            pos = ((pos - D) % L + L) % L

    print(
        f'Case #{case_num}: {counter}')
