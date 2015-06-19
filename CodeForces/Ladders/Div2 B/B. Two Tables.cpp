#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int a[55][55];
int b[55][55];

void read(int n, int m, int x[][55]) {
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = 0; j < m; ++j) {
      x[i][j] = s[j] == '0' ? 0 : 1;
    }
  }
}

int sum(int n1, int m1, int n2, int m2, int x, int y) {
  int result = 0;
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < m1; ++j) {
      if (i + x >= 0 && i + x < n2 && j + y >= 0 && j + y < m2) {
        result += a[i][j] * b[i + x][j + y];
      }
    }
  }
  return result;
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n1, m1; cin >> n1 >> m1;
  read(n1, m1, a);

  int n2, m2; cin >> n2 >> m2;
  read(n2, m2, b);

  int big_sum = -1;
  int rx, ry;
  for (int x = -50; x <= 50; ++x) {
    for (int y = -50; y <= 50; ++y) {
      int total = sum(n1, m1, n2, m2, x, y);
      if (total > big_sum) {
        big_sum = total;
        tie(rx, ry) = make_tuple(x, y);
      }
    }
  }
  cout << rx << " " << ry << "\n";
  return 0;
}