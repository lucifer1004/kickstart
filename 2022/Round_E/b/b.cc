#include <algorithm>
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
    printf("Case #%d: ", case_num);

    int n;
    read(n);
    vector<int> R(n);
    for (int i = 0; i < n; ++i)
      read(R[i]);
    vector<int> RS(R.begin(), R.end());
    sort(RS.begin(), RS.end());

    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
      auto it = upper_bound(RS.begin(), RS.end(), 2 * R[i]);
      if (it == RS.begin())
        continue;
      it--;
      if (*it == R[i]) {
        if (it == RS.begin())
          continue;
        it--;
      }
      ans[i] = *it;
    }

    for (int ai : ans)
      printf("%d ", ai);
    printf("\n");
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