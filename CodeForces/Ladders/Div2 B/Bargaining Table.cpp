#include <bits/stdc++.h>
using namespace std;

const int N = 25;

string square[N];
int dp[N][N];

int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> square[i];
    for (int j = 0; j < m; j++) {
      dp[i][j] = square[i][j] == '1' ? 1 : 0;
      if (i > 0) {
        dp[i][j] += dp[i - 1][j];
      }
      if (j > 0) {
        dp[i][j] += dp[i][j - 1];
      }
      if (i > 0 && j > 0) {
        dp[i][j] -= dp[i - 1][j - 1];
      }
    }
  }
  int result = 0;
  for (int x1 = 0; x1 < n; x1++) {
    for (int y1 = 0; y1 < m; y1++) {
      for (int x2 = x1; x2 < n; x2++) {
        for (int y2 = y1; y2 < m; y2++) {
          int value = dp[x2][y2];
          if (x1 > 0) {
            value -= dp[x1 - 1][y2];
          }
          if (y1 > 0) {
            value -= dp[x2][y1 - 1];
          }
          if (x1 > 0 && y1 > 0) {
            value += dp[x1 - 1][y1 - 1];
          }
          if (value == 0) {
            result = max(result, 2 * ((x2 - x1) + (y2 - y1) + 2));
          }
        }
      }
    }
  }
  cout << result << endl;
  return 0;
}