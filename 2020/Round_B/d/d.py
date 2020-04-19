from decimal import Decimal, getcontext
from random import randint

getcontext().prec = 64

fac = [Decimal(1)]
two = [Decimal(1)]
for i in range(1, 200005):
    fac.append(fac[-1] * Decimal(i))
    two.append(two[-1] * Decimal(2))


def c(n, k):
    return fac[n] / fac[n - k] / fac[k]


t = int(input())

for case_num in range(1, t + 1):
    w, h, l, u, r, d = map(int, input().split(' '))
    bad = Decimal(0)
    if u > 1:
        for j in range(l, r + 1):
            up = c(u + j - 3, u -
                   2) if j < w else sum([c(u + j - 3, k) for k in range(u - 1)])
            up /= two[u + j - 3]
            bad += up if j == w else up / Decimal(2)

    if l > 1:
        for i in range(u, d + 1):
            left = c(
                l + i - 3, l - 2) if i < h else sum([c(l + i - 3, k) for k in range(l - 1)])
            left /= two[l + i - 3]
            bad += left if i == h else left / Decimal(2)
    ans = Decimal(1) - bad
    print('Case #{}: {:.12f}'.format(case_num, abs(ans)))
