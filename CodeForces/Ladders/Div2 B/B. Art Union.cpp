#include <bits/stdc++.h>
using namespace std;

const int M = 50010;
const int N = 6;

int g[M][N];
int result[M];

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int m, n; cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    int end = 0;
    for (int j = 0; j < m; ++j) {
      int start = max(end, result[j]);
      result[j] = start + g[j][i];
      end = result[j];
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << result[i] << " ";
  }
  return 0;
}
