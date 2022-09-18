#include <cstdio>
#include <iostream>
#include <set>
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

    set<pair<int, int>> most_free, others;
    for (int i = 1; i <= K; ++i)
      most_free.emplace(0, i);
    for (int i = K + 1; i <= N; ++i)
      others.emplace(0, i);
    vector<int> meetings(N + 1);
    int ans = M, count = 0;
    for (int t = 0; t <= D; ++t) {
      if (t >= X) {
        for (int i : ends[t - X]) {
          auto pr = make_pair(meetings[P[i]], P[i]);
          if (most_free.count(pr))
            count -= meetings[P[i]];
          most_free.erase(pr);
          others.erase(make_pair(meetings[P[i]], P[i]));
          meetings[P[i]]--;
          most_free.emplace(meetings[P[i]], P[i]);
          count += meetings[P[i]];
        }
        while (most_free.size() > K) {
          others.insert(*most_free.rbegin());
          count -= most_free.rbegin()->first;
          most_free.erase(*most_free.rbegin());
        }
      }

      if (t >= X)
        ans = min(ans, count);

      for (int i : starts[t]) {
        auto pr = make_pair(meetings[P[i]], P[i]);
        if (most_free.count(pr))
          count -= meetings[P[i]];
        most_free.erase(pr);
        others.erase(make_pair(meetings[P[i]], P[i]));
        meetings[P[i]]++;
        others.emplace(meetings[P[i]], P[i]);
      }

      while (most_free.size() < K) {
        count += others.begin()->first;
        most_free.insert(*others.begin());
        others.erase(others.begin());
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