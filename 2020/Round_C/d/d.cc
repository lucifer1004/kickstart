#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template <class T> class FenwickTree {
  int limit;
  vector<T> arr;

  T lowbit(T x) { return x & (-x); }

public:
  FenwickTree(int limit) {
    this->limit = limit;
    arr = vector<T>(limit + 1);
  }

  void update(int idx, T delta) {
    for (; idx <= limit; idx += lowbit(idx))
      arr[idx] += delta;
  }

  T query(int idx) {
    T ans = 0;
    for (; idx > 0; idx -= lowbit(idx))
      ans += arr[idx];
    return ans;
  }
};

class Solution {
public:
  void solve(int case_num) {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    FenwickTree<ll> f1(n), f2(n);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      int sign = i % 2 == 1 ? 1 : -1;
      f1.update(i, sign * a[i]);
      f2.update(i, sign * a[i] * i);
    }
    ll ans = 0;
    for (int i = 0; i < q; ++i) {
      char c;
      cin >> c;
      if (c == 'U') {
        int x, v;
        cin >> x >> v;
        int sign = x % 2 == 1 ? 1 : -1;
        f1.update(x, sign * (v - a[x]));
        f2.update(x, sign * (v - a[x]) * x);
        a[x] = v;
      } else {
        int l, r;
        cin >> l >> r;
        int sign = l % 2 == 1 ? 1 : -1;
        ll s1 = f1.query(r) - f1.query(l - 1);
        s1 *= (l - 1) * -sign;
        ll s2 = f2.query(r) - f2.query(l - 1);
        s2 *= sign;
        ans += s2 + s1;
      }
    }
    cout << "Case #" << case_num << ": " << ans << endl;
  }
};

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solution solution = Solution();
    solution.solve(i);
  }
}