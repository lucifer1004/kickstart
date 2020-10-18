#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

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
    int w, n;
    read(w), read(n);
    vector<int> x(w);
    for (int i = 0; i < w; ++i)
      read(x[i]);
    sort(x.begin(), x.end());
    for (int i = 0; i < w; ++i)
      x.emplace_back(x[i] + n);
    vector<ll> sum(2 * w + 1);
    for (int i = 1; i <= 2 * w; ++i)
      sum[i] = sum[i - 1] + x[i - 1];
    ll ans = LLONG_MAX;
    for (int i = 0; i < w; ++i) {
      int l = x[i] + n / 2;
      int r = x[i] + n / 2 + 1;
      int R = upper_bound(x.begin(), x.end(), l) - x.begin();
      int L = R - 1;
      ll sl = sum[L + 1] - sum[i] - (ll)x[i] * (L - i + 1);
      ll sr = (ll)x[i + w] * (i + w - R + 1) - (sum[i + w + 1] - sum[R]);
      ans = min(ans, sl + sr);
    }
    printf("%lld\n", ans);
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