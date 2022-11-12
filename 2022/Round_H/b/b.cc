#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

int main() {
  vector<int> memo(MAXN, INF);
  memo[1] = 1;
  for (int i = 1; i < MAXN; ++i) {
    if (i + 1 < MAXN)
      memo[i + 1] = min(memo[i + 1], memo[i] + 1);
    for (int j = i + i; j < MAXN; j += i)
      memo[j] = min(memo[j], memo[i] + (j / i - 1) * 2 + 4);
  }

  int T;
  read(T);
  for (int case_num = 1; case_num <= T; ++case_num) {
    printf("Case #%d: ", case_num);
    int L;
    read(L);
    printf("%d\n", memo[L]);
  }
}