#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

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

    string s, f;
    cin >> s >> f;

    vector<bool> good(26);
    for (char ch : f)
      good[ch - 'a'] = true;

    vector<int> cost(26);
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j)
        if (good[(i + j) % 26] || good[(i + 26 - j) % 26]) {
          cost[i] = j;
          break;
        }

    int ans = 0;
    for (char ch : s)
      ans += cost[ch - 'a'];

    cout << ans << endl;
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