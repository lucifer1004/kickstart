#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2505;

template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-') sig = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

class Solution {
 public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);

    int n, m;
    read(n);
    vector<int> s(n);
    vector<vector<int>> c(N);
    for (int i = 0; i < n; ++i) read(s[i]);
    read(m);
    vector<int> k(m);
    for (int i = 0; i < m; ++i) {
      read(k[i]);
      c[k[i]].push_back(i);
    }

    vector<vector<int>> L(m), R(m);
    vector<int> now(N, -1);
    for (int i = 0; i < m; ++i) {
      now[k[i]] = i;
      L[i] = now;
    }
    now = vector<int>(N, -1);
    for (int i = m - 1; i >= 0; --i) {
      now[k[i]] = i;
      R[i] = now;
    }

    vector<int> dp(m, INF);
    for (int si : c[s[0]]) dp[si] = 0;
    for (int i = 1; i < n; ++i) {
      vector<int> ndp(m, INF);
      for (int u : c[s[i - 1]]) {
        if (L[u][s[i]] != -1)
          ndp[L[u][s[i]]] = min(ndp[L[u][s[i]]], dp[u] + u - L[u][s[i]]);
        if (R[u][s[i]] != -1)
          ndp[R[u][s[i]]] = min(ndp[R[u][s[i]]], dp[u] + R[u][s[i]] - u);
      }
      dp = move(ndp);
    }

    printf("%d", *min_element(dp.begin(), dp.end()));
    printf("\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  for (int i = 1; i <= t; ++i) {
    Solution solution = Solution();
    solution.solve(i);
  }
}