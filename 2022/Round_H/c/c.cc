#include <bits/stdc++.h>

using namespace std;

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

class Solution {
  int N;
  vector<int> A;
  vector<vector<int>> adj;

public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);

    read(N);
    A.resize(N);
    for (int i = 0; i < N; ++i)
      read(A[i]);

    adj.resize(N);
    for (int i = 0; i < N - 1; ++i) {
      int u, v;
      read(u);
      read(v);
      --u, --v;
      if (A[u] < A[v])
        swap(u, v);
      if (A[u] > A[v])
        adj[u].push_back(v);
    }

    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) { return A[a] < A[b]; });

    int ans = 0;
    vector<int> dp(N, 1);
    for (int i : order) {
      for (int j : adj[i])
        dp[i] += dp[j];
      ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
  }
};

int main() {
  int t;
  read(t);
  for (int i = 1; i <= t; ++i) {
    Solution solution = Solution();
    solution.solve(i);
  }
}