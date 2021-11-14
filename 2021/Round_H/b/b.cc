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

int mp[128]{};

class Solution {
public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);
    int n;
    string p;
    cin >> n;
    cin >> p;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
      v[i] = mp[p[i]];

    int ans = 0;
    for (int k = 0; k < 3; ++k) {
      for (int i = 0; i < n; ++i) {
        if (!(v[i] & (1 << k)))
          continue;
        ans++;
        int j = i;
        while (j + 1 < n && (v[j + 1] & (1 << k)))
          j++;
        i = j;
      }
    }

    cout << ans << endl;
  }
};

int main() {
  int t;
  read(t);

  mp['U'] = 0;
  mp['R'] = 1;
  mp['Y'] = 2;
  mp['B'] = 4;
  mp['O'] = 3;
  mp['P'] = 5;
  mp['G'] = 6;
  mp['A'] = 7;

  for (int i = 1; i <= t; ++i) {
    Solution solution = Solution();
    solution.solve(i);
  }
}