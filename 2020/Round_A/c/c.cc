#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve(int t) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> m(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &m[i]);
    vector<int> delta(n - 1);
    for (int i = 0; i < n - 1; ++i)
      delta[i] = m[i + 1] - m[i];
    int l = 1, r = 1e9;
    while (l <= r) {
      int mid = (l + r) / 2;
      int cnt = 0;
      for (int i : delta) {
        if (i > mid)
          cnt += (i - 1) / mid;
      }
      if (cnt > k)
        l = mid + 1;
      else
        r = mid - 1;
    }
    printf("Case #%d: %d\n", t, l);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d", &t);
  int i = 1;
  while (i <= t) {
    Solution solution = Solution();
    solution.solve(i);
    i++;
  }
}