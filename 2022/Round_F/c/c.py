from sys import stdin
from collections import defaultdict
from heapq import *
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    D, N, X = read_ints()
    seeds = [tuple(read_ints()) for _ in range(N)]
    days = sorted(list(set([seed[1] for seed in seeds] + [D])))
    groups = defaultdict(list)
    for q, l, v in seeds:
        groups[l].append((q, v))

    hp = []
    ans = 0
    last = 0
    for day in days:
        duration = day - last
        max_plant = duration * X
        planted = 0
        while len(hp) > 0 and planted < max_plant:
            v, q = heappop(hp)
            v = -v
            can_plant = min(q, max_plant - planted)
            ans += can_plant * v
            planted += can_plant
            if q > can_plant:
                heappush(hp, (-v, q - can_plant))
        last = day
        for q, v in groups[day]:
            heappush(hp, (-v, q))

    print(f'Case #{case_num}: {ans}')
