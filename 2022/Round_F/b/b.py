from sys import stdin
from collections import deque
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(1, t + 1):
    n, q = read_ints()
    adj = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = read_ints()
        adj[u].append(v)
        adj[v].append(u)

    depth = [0] * (n + 1)
    depth[1] = 1
    cnt = [0] * (n + 1)
    dq = deque()
    dq.append(1)
    while len(dq) > 0:
        u = dq.popleft()
        cnt[depth[u]] += 1
        for v in adj[u]:
            if depth[v] == 0:
                depth[v] = depth[u] + 1
                dq.append(v)

    for _ in range(q):
        read_int()

    ans = 0
    for i in range(1, n + 1):
        if q >= cnt[i]:
            ans += cnt[i]
            q -= cnt[i]
        else:
            break

    print(f'Case #{case_num}: {ans}')
