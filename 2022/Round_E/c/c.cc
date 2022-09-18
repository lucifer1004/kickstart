#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

std::vector<int> manacher(const std::string &s) {
  std::string t;
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (i > 0)
      t.push_back('$');
    t.push_back(c);
  }
  std::vector<int> a(t.size());
  for (int i = 0, l = 0, r = -1; i < t.size(); ++i) {
    int j = (i > r) ? 1 : std::min(a[l + r - i], r - i + 1);
    while (i >= j && i + j < t.size() && t[i - j] == t[i + j])
      j++;
    a[i] = j--;
    if (i + j > r) {
      l = i - j;
      r = i + j;
    }
  }
  return a;
}

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
    string P;
    cin >> P;

    auto manach = manacher(P);

    auto check = [&](int l, int r) {
      int mid = l + r;
      return manach[mid] >= mid - (2 * l) + 1;
    };

    string Q = P;
    for (int i = 0; i < n - 1; ++i) {
      if (check(0, i) && check(i + 1, n - 1)) {
        Q = P.substr(0, i + 1);
        break;
      }
    }

    cout << Q << endl;
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