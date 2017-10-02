#include <bits/stdc++.h>
using namespace std;

char square[25][25];

int main(int argc, char** argv) {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", square[i]);
  }
  int result = 0;
  for (int x1 = 0; x1 < n; x1++) {
    for (int y1 = 0; y1 < m; y1++) {
      for (int x2 = x1; x2 < n; x2++) {
        for (int y2 = y1; y2 < m; y2++) {
          bool ok = true;
          for (int i = x1; i <= x2 && ok; i++) {
            for (int j = y1; j <= y2 && ok; j++) {
              ok &= square[i][j] == '0';
            }
          }
          if (ok) {
            result = max(result, 2 * ((x2 - x1) + (y2 - y1) + 2));
          }
        }
      }
    }
  }
  printf("%d\n", result);
  return 0;
}