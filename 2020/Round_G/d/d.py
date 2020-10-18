N = 0
t = int(input())
store = []
for case_num in range(1, t + 1):
    n = int(input())
    N = max(n + 1, N)
    a = list(map(int, input().split()))
    store.append(a)

coeff = [[0.0 for _ in range(N)] for _ in range(N)]
coeff[1][1] = 0.0
coeff[2][1] = 1.0
coeff[2][2] = 1.0

for i in range(3, N):
    coeff[i][1] = coeff[i - 1][1] * (i - 1) + 1
    coeff[i][i] = coeff[i - 1][i - 1] * (i - 1) + 1
    for j in range(2, i):
        coeff[i][j] = coeff[i - 1][j] * \
            (i - j) + coeff[i - 1][j - 1] * (j - 1) + 2
    for j in range(1, i + 1):
        coeff[i][j] /= i - 1

for case_num in range(1, t + 1):
    a = store[case_num - 1]
    n = len(a)
    s = sum([a[i] * coeff[n][i + 1] for i in range(n)])
    print('Case #{}: {:.6f}'.format(case_num, s))
