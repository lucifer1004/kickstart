#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  static void solve(int t) {
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    vector<int> dp(p + 1);
    vector<vector<int>> a;
    a.assign(n, {0});
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < k; ++j) {
        int value;
        scanf("%d", &value);
        a[i].emplace_back(a[i].back() + value);
      }
    for (int i = 0; i < n; ++i) {
      for (int j = p; j > 0; --j)
        for (int s = 1; s <= min(j, k); ++s)
          dp[j] = max(dp[j], dp[j - s] + a[i][s]);
    }
    printf("Case #%d: %d\n", t, dp[p]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  int i = 1;
  while (i <= t)
    Solution::solve(i++);
}