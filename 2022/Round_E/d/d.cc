#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

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

const int d[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

class Solution {
public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);
    int N, P, M, Ar, Ac;
    cin >> N >> P >> M >> Ar >> Ac;
    Ar--, Ac--;

    vector<char> op(4);
    vector<int> k(4);
    for (int i = 0; i < 4; ++i)
      cin >> op[i] >> k[i];

    auto calc = [&](ll now, int i) {
      if (op[i] == '+')
        return now + k[i];
      else if (op[i] == '-')
        return now - k[i];
      else if (op[i] == '*')
        return now * k[i];
      else
        return (ll)floor((double)now / k[i]);
    };

    vector<int> x(P), y(P), c(P);
    vector<vector<int>> p(N, vector<int>(N, -1));
    for (int i = 0; i < P; ++i) {
      cin >> x[i] >> y[i] >> c[i];
      x[i]--, y[i]--;
      p[x[i]][y[i]] = i;
    }

    vector<vector<vector<ll>>> dp(
        N, vector<vector<ll>>(N, vector<ll>(1 << P, LLONG_MIN)));
    dp[Ar][Ac][0] = 0;
    if (p[Ar][Ac] != -1)
      dp[Ar][Ac][1 << p[Ar][Ac]] = c[p[Ar][Ac]];

    for (int i = 0; i < M; ++i) {
      vector<vector<vector<ll>>> ndp(
          N, vector<vector<ll>>(N, vector<ll>(1 << P, LLONG_MIN)));
      for (int x = 0; x < N; ++x)
        for (int y = 0; y < N; ++y) {
          for (int state = 0; state < (1 << P); ++state) {
            if (dp[x][y][state] == LLONG_MIN)
              continue;
            ll now = dp[x][y][state];
            ndp[x][y][state] = max(ndp[x][y][state], dp[x][y][state]);

            for (int direction = 0; direction < 4; ++direction) {
              int nx = x + d[direction][0], ny = y + d[direction][1];
              if (nx < 0 || nx == N || ny < 0 || ny == N)
                continue;
              ll nxt = calc(now, direction);
              ndp[nx][ny][state] = max(ndp[nx][ny][state], nxt);
              if (p[nx][ny] != -1 && ((1 << p[nx][ny]) & state) == 0) {
                int nxt_state = state ^ (1 << p[nx][ny]);
                ndp[nx][ny][nxt_state] =
                    max(ndp[nx][ny][nxt_state], nxt + c[p[nx][ny]]);
              }
            }
          }
        }

      dp = move(ndp);
    }

    ll ans = LLONG_MIN;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) {
        ans = max(ans, dp[i][j][(1 << P) - 1]);
      }

    if (ans == LLONG_MIN)
      printf("IMPOSSIBLE\n");
    else
      printf("%lld\n", ans);
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