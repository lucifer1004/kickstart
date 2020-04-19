t = int(input())
mod = int(1e9)
idict = dict()
for c in 'NSWE':
    idict[c] = 0


def is_digit(c):
    delta = ord(c) - ord('0')
    return 0 <= delta <= 9


for case_num in range(1, t+1):
    s = input()
    a = [1]
    b = [idict.copy()]
    fold = 0
    for c in s:
        if is_digit(c):
            fold = fold * 10 + ord(c) - ord('0')
        elif c == '(':
            a.append(fold)
            fold = 0
            b.append(idict.copy())
        elif c == ')':
            for d in 'NSWE':
                b[-2][d] += a[-1] * b[-1][d]
            a.pop()
            b.pop()
        else:
            b[-1][c] += 1
    x = (b[0]['E'] - b[0]['W']) % mod
    if x < 0:
        x += mod
    y = (b[0]['S'] - b[0]['N']) % mod
    if y < 0:
        y += mod
    print('Case #{}: {} {}'.format(case_num, x + 1, y + 1))
