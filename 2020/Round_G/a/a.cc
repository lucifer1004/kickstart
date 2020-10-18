#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void solve(int case_num) {
    cout << "Case #" << case_num << ": ";
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
      if (i + 3 < n && s.substr(i, 4) == "KICK")
        a.emplace_back(i);
      if (i + 4 < n && s.substr(i, 5) == "START")
        b.emplace_back(i);
    }
    int ans = 0;
    int j = 0;
    for (int i = 0; i < a.size(); ++i) {
      while (j < b.size() && b[j] < a[i])
        j++;
      ans += b.size() - j;
    }
    cout << ans << endl;
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