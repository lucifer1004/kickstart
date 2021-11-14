#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const int K = 19;

ll fexp(ll x, ll y) {
  ll ans = 1;
  while (y) {
    if (y & 1)
      ans = ans * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ans;
}

ll rev(ll x) { return fexp(x, MOD - 2); }

const ll BASE = rev(1000000);

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
  vector<vector<int>> adj;
  vector<vector<int>> parent;
  vector<int> depth;
  vector<vector<ll>> PPT, PPF;

  pair<ll, ll> calc(int p, int u) {
    ll r = 1, s = 0;

    for (int k = K - 1; k >= 0; --k) {
      if (depth[parent[p][k]] >= depth[u]) {
        auto [nr, ns] = combine(PPT[p][k], PPF[p][k], r, s);
        r = nr, s = ns;
        p = parent[p][k];
      }
    }

    return {r, s};
  }

  static pair<ll, ll> combine(ll a, ll b, ll c, ll d) {
    ll r = (a * c % MOD + (MOD + 1 - a) * d % MOD) % MOD;
    ll s = (b * c % MOD + (MOD + 1 - b) * d % MOD) % MOD;
    return {r, s};
  }

public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);

    int N, Q;
    read(N), read(Q);
    adj = vector<vector<int>>(N + 1);
    parent = vector<vector<int>>(N + 1, vector<int>(K));
    depth = vector<int>(N + 1);
    PPT = vector<vector<ll>>(N + 1, vector<ll>(K));
    PPF = vector<vector<ll>>(N + 1, vector<ll>(K));

    ll P_ROOT;
    read(P_ROOT);
    P_ROOT = P_ROOT * BASE % MOD;
    depth[1] = 1;
    PPT[1][0] = 1;

    for (int i = 2; i <= N; ++i) {
      int p, pt, pf;
      read(p), read(pt), read(pf);
      adj[p].push_back(i);
      parent[i][0] = p;
      depth[i] = depth[p] + 1;
      PPT[i][0] = 1LL * pt * BASE % MOD;
      PPF[i][0] = 1LL * pf * BASE % MOD;
    }

    for (int k = 1; k < K; ++k) {
      for (int i = 2; i <= N; ++i) {
        int p = parent[i][k - 1];
        int u = parent[p][k - 1];
        if (u != 0) {
          parent[i][k] = u;
          auto [r, s] = combine(PPT[p][k - 1], PPF[p][k - 1], PPT[i][k - 1],
                                PPF[i][k - 1]);
          PPT[i][k] = r, PPF[i][k] = s;
        }
      }
    }

    for (int i = 1; i <= Q; ++i) {
      int u, v;
      read(u), read(v);

      if (depth[u] > depth[v])
        swap(u, v);

      int p = u, q = v;
      for (int k = K - 1; k >= 0; --k) {
        if (depth[parent[q][k]] >= depth[p])
          q = parent[q][k];
      }

      assert(depth[p] == depth[q]);

      for (int k = K - 1; k >= 0; --k) {
        if (parent[p][k] != parent[q][k]) {
          p = parent[p][k];
          q = parent[q][k];
        }
      }

      if (p != q)
        p = parent[p][0];

      auto [a, b] = calc(p, 1);
      auto [c, d] = calc(u, p);
      auto [e, f] = calc(v, p);

      ll pt = (P_ROOT * a % MOD + (MOD + 1 - P_ROOT) * b % MOD) % MOD;
      ll pf = (MOD + 1 - pt) % MOD;

      ll ans = (pt * c % MOD * e % MOD + pf * d % MOD * f % MOD) % MOD;

      cout << ans << " ";
    }

    cout << endl;
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