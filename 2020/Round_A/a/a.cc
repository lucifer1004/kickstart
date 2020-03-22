#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  static void solve(int t) {
    int n, b;
    scanf("%d%d", &n, &b);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (sum + a[i] <= b) {
        sum += a[i];
        ans++;
      } else
        break;
    }
    printf("Case #%d: %d\n", t, ans);
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