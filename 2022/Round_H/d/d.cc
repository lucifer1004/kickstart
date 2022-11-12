#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

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
  int N;
  vector<int> A;

public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);

    read(N);
    A.resize(N + 1);
    for (int i = 1; i <= N; ++i)
      read(A[i]);

    vector<bool> vis(N + 1);
    vector<int> cycles(N + 1);
    vector<pair<int, int>> nums;

    for (int i = 1; i <= N; ++i) {
      if (vis[i])
        continue;

      int num = 1;
      vis[i] = true;
      int nxt = A[i];

      while (nxt != i) {
        vis[nxt] = true;
        num++;
        nxt = A[nxt];
      }

      cycles[num]++;
    }

    for (int i = 1; i <= N; ++i) {
      if (cycles[i] == 0)
        continue;

      int unit = 1, cycle = cycles[i];
      while (cycle >= unit) {
        cycle -= unit;
        nums.emplace_back(unit * i, unit);
        unit <<= 1;
      }

      if (cycle > 0)
        nums.emplace_back(cycle * i, cycle);
    }

    vector<int> knapsack(N + 1, INF);
    knapsack[0] = 0;
    for (auto [num, wei] : nums) {
      for (int i = N; i >= num; --i)
        knapsack[i] = min(knapsack[i], knapsack[i - num] + wei);
    }

    vector<int> knapsack_greater(N + 2, INF);
    for (int i = N; i >= 1; --i)
      knapsack_greater[i] = min(knapsack_greater[i + 1], knapsack[i]);

    vector<bool> equal_or_greater(N + 2);
    for (int i = N; i >= 1; --i) {
      if (cycles[i] > 0)
        equal_or_greater[i] = true;
      else
        equal_or_greater[i] = equal_or_greater[i + 1];
    }

    for (int k = 1; k <= N; ++k) {
      if (cycles[k] > 0) {
        printf("0 ");
      } else if (equal_or_greater[k + 1]) {
        printf("1 ");
      } else {
        printf("%d ", min(knapsack[k] - 1, knapsack_greater[k + 1]));
      }
    }

    printf("\n");
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