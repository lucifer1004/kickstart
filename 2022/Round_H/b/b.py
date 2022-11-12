from heapq import *

T = int(input())
for t in range(T):
    L = int(input())
    memo = {(0, 0): 0}
    hp = [(0, 0, 0)]  # (cost, num, note)

    while len(hp) > 0:
        cost, num, note = heappop(hp)
        if note > 0 and num + note <= L:
            nxt = (num + note, note)
            if nxt not in memo or memo[nxt] > cost + 2:
                memo[nxt] = cost + 2
                heappush(hp, (cost + 2, num + note, note))
        if num > note and num + num <= L:
            nxt = (num, num)
            if nxt not in memo or memo[nxt] > cost + 4:
                memo[nxt] = cost + 4
                heappush(hp, (cost + 4, num, num))
        if num < L:
            nxt = (num + 1, note)
            if nxt not in memo or memo[nxt] > cost + 1:
                memo[nxt] = cost + 1
                heappush(hp, (cost + 1, num + 1, note))

    ans = L
    for note in range(L):
        if (L, note) in memo:
            ans = min(ans, memo[(L, note)])

    print(f'Case #{t + 1}: {ans}')
