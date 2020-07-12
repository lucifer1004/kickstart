#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define K 21

using namespace std;

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
  vector<vector<int>> adj, parent;
  vector<int> depth, ac, bc;
  void dfs(int u, int p) {
    parent[u][0] = p;
    depth[u] = depth[p] + 1;
    for (int i = 1; i < K; ++i)
      parent[u][i] = parent[parent[u][i - 1]][i - 1];
    for (int v : adj[u])
      dfs(v, u);
  }

  int walk(int u, int d) {
    for (int k = K - 1; k >= 0; --k) {
      if (d & (1 << k))
        u = parent[u][k];
    }
    return u;
  }

public:
  void solve(int case_num) {
    int n, a, b;
    read(n), read(a), read(b);
    adj = vector<vector<int>>(n + 1);
    for (int i = 2; i <= n; ++i) {
      int v;
      read(v);
      adj[v].emplace_back(i);
    }
    parent = vector<vector<int>>(n + 1, vector<int>(K));
    depth = vector<int>(n + 1);
    dfs(1, 0);
    vector<int> ac(n + 1, 1), bc(n + 1, 1);
    vector<int> order(n);
    for (int i = 0; i < n; ++i)
      order[i] = i + 1;
    sort(order.begin(), order.end(),
         [&](int i, int j) { return depth[i] > depth[j]; });
    for (int i : order) {
      int ua = walk(i, a);
      if (ua > 0)
        ac[ua] += ac[i];
      int ub = walk(i, b);
      if (ub > 0)
        bc[ub] += bc[i];
    }
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += (double)(ac[i] + bc[i]) * n;
      ans -= (double)ac[i] * bc[i];
    }
    printf("Case #%d: %.12f\n", case_num, ans / n / n);
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