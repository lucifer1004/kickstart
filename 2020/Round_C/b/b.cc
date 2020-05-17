#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
  int r, c;
  bool found = false;
  string ans, cans;
  set<char> avail;
  vector<string> wall;
  map<char, bool> used;
  map<char, vector<pair<int, int>>> sticks;

  void dfs() {
    if (avail.empty()) {
      found = true;
      ans = cans;
    }
    if (found)
      return;
    vector<char> va(avail.begin(), avail.end());
    for (char ch : va) {
      bool ok = true;
      used[ch] = true;
      for (pair<int, int> p : sticks[ch]) {
        if (p.first < r - 1 && !used[wall[p.first + 1][p.second]]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        avail.erase(ch);
        cans.push_back(ch);
        dfs();
        if (found)
          return;
        avail.insert(ch);
        cans.pop_back();
      }
      used[ch] = false;
    }
  }

public:
  void solve(int case_num) {
    cin >> r >> c;
    wall = vector<string>(r);
    for (int i = 0; i < r; ++i)
      cin >> wall[i];
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        sticks[wall[i][j]].push_back({i, j});
        avail.insert(wall[i][j]);
      }
    dfs();
    cout << "Case #" << case_num << ": " << (found ? ans : "-1") << endl;
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