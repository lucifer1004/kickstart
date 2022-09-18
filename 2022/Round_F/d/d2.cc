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
    int N, K, X, D, M;
    read(N), read(K), read(X), read(D), read(M);
    vector<int> P(M), L(M), R(M);
    vector<vector<int>> starts(D + 1), ends(D + 1);
    for (int i = 0; i < M; ++i) {
      read(P[i]), read(L[i]), read(R[i]);
      starts[L[i]].push_back(i);
      ends[R[i]].push_back(i);
    }

    int largest = 0;
    int largest_count = K;
    vector<int> freq(M + 1);
    freq[0] = N;
    vector<int> meetings(N + 1);
    int ans = M, count = 0;
    for (int t = 0; t <= D; ++t) {
      if (t >= X) {
        for (int i : ends[t - X]) {
          freq[meetings[P[i]]]--;
          freq[--meetings[P[i]]]++;
          if (meetings[P[i]] < largest) {
            count--;
            if (meetings[P[i]] == largest - 1)
              largest_count--;
          }
          if (largest_count == 0)
            largest_count = freq[--largest];
        }
      }

      if (t >= X)
        ans = min(ans, count);

      for (int i : starts[t]) {
        freq[meetings[P[i]]]--;
        freq[++meetings[P[i]]]++;
        if (meetings[P[i]] < largest) {
          count++;
        } else if (meetings[P[i]] == largest) {
          count++;
          largest_count++;
        } else if (meetings[P[i]] == largest + 1 &&
                   largest_count > freq[largest]) {
          count++;
          largest++;
          largest_count = 1;
        }
      }
    }

    printf("%d\n", ans);
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