#include <bits/stdc++.h>
using namespace std;

int g[110][110];

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, m, d; cin >> n >> m >> d;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  int result = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int count = 0;
      const int value = g[i][j];
      bool can = true;
      for (int x = 0; x < n && can; ++x) {
        for (int y = 0; y < m && can; ++y) {
          if (x == i && y == j) {
            continue;
          }
          const int steps = abs(g[x][y] - value);
          if (steps % d != 0) {
            can = false;
          } else {
            count += steps / d;
          }
        }
      }
      if (can) {
        result = min(result, count);
      }
    }
  }
  cout << (result == numeric_limits<int>::max() ? -1 : result) << endl;
  return 0;
}