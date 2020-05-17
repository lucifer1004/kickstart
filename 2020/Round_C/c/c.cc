#include <cstring>
#include <iostream>
#include <vector>
#define OFFSET 10000001
#define MAXN 20000005

using namespace std;
typedef long long ll;

int cnt[MAXN];
vector<int> good;

class Solution {
public:
  void solve(int case_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    int s = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
      for (int j : good) {
        int rest = s - j;
        int idx = rest + OFFSET;
        if (idx < 0 || idx >= MAXN)
          continue;
        ans += cnt[rest + OFFSET];
      }
      cnt[s + OFFSET]++;
    }
    s = 0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
      cnt[s + OFFSET]--;
    }
    cout << "Case #" << case_num << ": " << ans << endl;
  }
};

int main() {
  int t;
  cin >> t;
  memset(cnt, 0, sizeof(cnt));
  cnt[OFFSET] = 1;
  for (int i = 0; i * i <= 1e7; ++i)
    good.emplace_back(i * i);
  for (int i = 1; i <= t; ++i) {
    Solution solution = Solution();
    solution.solve(i);
  }
}