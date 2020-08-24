#include <cstdio>
#include <iostream>
#include <vector>

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
public:
  void solve(int case_num) {
    int n;
    read(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      read(a[i]);
    int ans = 2;
    vector<int> dp(n);
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < n; ++i) {
      if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
        dp[i] = dp[i - 1] + 1;
      else
        dp[i] = 2;
      ans = max(ans, dp[i]);
    }
    printf("Case #%d: %d\n", case_num, ans);
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