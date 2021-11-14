#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

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
public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);
    int n;
    string s;

    cin >> n;
    cin >> s;

    vector<int> v(n), pre(n), nxt(n);
    for (int i = 0; i < n; i++) {
      v[i] = s[i] - '0';
      pre[i] = i == 0 ? -1 : i - 1;
      nxt[i] = i == n - 1 ? -1 : i + 1;
    }

    vector<unordered_set<int>> fst(10);
    for (int i = 0; i < n - 1; i++) {
      if ((v[i] + 1) % 10 == v[i + 1]) {
        fst[v[i]].insert(i);
      }
    }

    bool changed = true;
    while (changed) {
      changed = false;
      for (int i = 0; i < 10; ++i) {
        vector<int> vv(fst[i].begin(), fst[i].end());
        fst[i].clear();

        if (vv.size() > 0)
          changed = true;

        for (int x : vv) {
          v[x] = (v[x] + 2) % 10;
          if (nxt[nxt[x]] != -1)
            pre[nxt[nxt[x]]] = x;

          if (pre[x] != -1) {
            fst[v[pre[x]]].erase(pre[x]);
          }

          fst[v[nxt[x]]].erase(nxt[x]);
          nxt[x] = nxt[nxt[x]];

          if (pre[x] != -1 && (v[pre[x]] + 1) % 10 == v[x]) {
            fst[v[pre[x]]].insert(pre[x]);
          }

          if (nxt[x] != -1 && (v[x] + 1) % 10 == v[nxt[x]]) {
            fst[v[x]].insert(x);
          }
        }
      }
    }

    string ans;
    int p = 0;
    while (p != -1) {
      ans.push_back(v[p] + '0');
      p = nxt[p];
    }

    cout << ans << endl;
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