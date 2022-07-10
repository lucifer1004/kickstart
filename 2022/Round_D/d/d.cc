#include <atcoder/scc>
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
using ll = long long;

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
    int n, m, k;
    read(n), read(m), read(k);
    atcoder::scc_graph g(n);
    vector<pair<int, int>> e;
    for (int i = 0; i < m; ++i) {
      int u, v;
      read(u), read(v);
      u--, v--;
      g.add_edge(u, v);
      e.emplace_back(u, v);
    }

    vector<vector<int>> comp = g.scc();
    vector<int> mp(n);
    int c = comp.size();
    for (int i = 0; i < c; ++i) {
      for (int j : comp[i]) mp[j] = i;
    }

    vector<unordered_set<int>> adj(c);
    for (auto [u, v] : e)
      if (mp[u] != mp[v]) adj[mp[v]].insert(mp[u]);

    int ans = 0;
    for (int i = 0; i < c; ++i) {
      unordered_set<int> vis;
      vis.insert(i);
      int now = comp[i].size();
      queue<int> q;
      q.push(i);

      while (now <= k && !q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
          if (!vis.count(v)) {
            vis.insert(v);
            q.push(v);
            now += comp[v].size();
          }
        }
      }

      if (now > k) ans += comp[i].size();
    }

    printf("%d\n", ans);
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