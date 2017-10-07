/*
ID: omar.se1
LANG: C++11
TASK: beads
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 355;
const int B = 0;
const int R = 1;

int f[2][M * 2];
int b[2][M * 2];

int main() {
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  int n;
  cin >> n;
  string necklace;
  cin >> necklace;
  necklace += necklace;
  const int m = (int) necklace.length();
  for (int i = 1; i <= m; i++) {
    if (necklace[i - 1] == 'r') {
      f[R][i] = f[R][i - 1] + 1;
    } else if (necklace[i - 1] == 'b') {
      f[B][i] = f[B][i - 1] + 1;
    } else {
      f[B][i] = f[B][i - 1] + 1;
      f[R][i] = f[R][i - 1] + 1;
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    if (necklace[i] == 'r') {
      b[R][i] = b[R][i + 1] + 1;
    } else if (necklace[i] == 'b') {
      b[B][i] = b[B][i + 1] + 1;
    } else {
      b[B][i] = b[B][i + 1] + 1;
      b[R][i] = b[R][i + 1] + 1;
    }
  }
  int result = 0;
  for (int i = 1; i < m; i++) {
    result = max(result, max(f[B][i], f[R][i]) + max(b[B][i], b[R][i]));
  }
  result = min(result, n);
  cout << result << endl;
  return 0;
}
