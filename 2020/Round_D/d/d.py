from random import randint, shuffle

n = 1000
q = 1000
a = [i + 1 for i in range(n - 1)]
shuffle(a)
print(1)
print(n, q)
print(' '.join(map(str, a)))
for i in range(q):
    s = randint(1, n)
    k = randint(1, n)
    print(s, k)
