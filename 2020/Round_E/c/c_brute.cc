#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f

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
    printf("Case #%d: ", case_num);
    int n;
    read(n);
    vector<int> e(n + 1), r(n + 1);
    FenwickTree<ll> ft(n), ft1(n);
    for (int i = 1; i <= n; ++i) {
      read(e[i]), read(r[i]);
      ft.update(i, e[i]);
      ft1.update(i, e[i]);
    }
    ll hi_val = ft.query(n);
    ll current = hi_val;
    ll right = 0;
    for (int i = 1; i <= n; ++i) {
    }
    priority_queue<int> pq;
    int min_del = 0, now_del = 0;
    ll permit = INF;
    bool shut = false;
    for (int i = 1; i <= n; ++i) {
      ll left = ft.query(i - 1);
      ll right = ft.query(n) - ft.query(i);
      ll seg = left + right;
      if (seg < r[i]) {
        shut = true;
        if (permit < e[i])
          break;
        permit -= e[i];
        ft.update(i, -e[i]);
        current -= e[i];
        now_del++;
      } else {
        permit = min(permit, seg - r[i]);
        current += e[i];
        if (hi_val < current) {
          hi_val = current;
          min_del = now_del;
        }
      }
    }
    if (!shut) {
      printf("0 INDEFINITELY\n");
      return;
    }
    bool changed = true;
    int deleted = 0;
    vector<bool> exist(n + 1, true);
    while (changed) {
      changed = false;
      for (int i = 1; i <= n; ++i) {
        if (!exist[i])
          continue;
        ll left = ft1.query(i - 1);
        ll right = ft1.query(n) - ft1.query(i);
        ll seg = left + right;
        if (seg < r[i]) {
          deleted++;
          changed = true;
          ft1.update(i, -e[i]);
          exist[i] = false;
        }
      }
    }
    if (deleted < n)
      printf("%d INDEFINITELY\n", deleted);
    else
      printf("%d %lld\n", min_del, hi_val);
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