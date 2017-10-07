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
  for (int i = 0; i < m; i++) {
    if (necklace[i] == 'b') {
      f[B][i] = 1;
      b[B][i] = 1;
    } else if (necklace[i] == 'r') {
      f[R][i] = 1;
      b[R][i] = 1;
    } else {
      f[R][i] = f[B][i] = 1;
      b[R][i] = b[B][i] = 1;
    }
  }
  for (int i = 1; i < m; i++) {
    if (f[B][i] != 0) {
      f[B][i] += f[B][i - 1];
    }
    if (f[R][i] != 0) {
      f[R][i] += f[R][i - 1];
    }
  }
  for (int i = m - 2; i >= 0; i--) {
    if (b[B][i] != 0) {
      b[B][i] += b[B][i + 1];
    }
    if (b[R][i] != 0) {
      b[R][i] += b[R][i + 1];
    }
  }
  int result = 0;
  for (int i = 1; i < m - 1; i++) {
    const int c1 = max(f[B][i], f[R][i]);
    const int c2 = max(b[B][i + 1], b[R][i + 1]);
    result = max(result, c1 + c2);
  }
  result = min(result, n);
  cout << result << endl;
  return 0;
}
