/*
ID: omar.se1
LANG: C++11
TASK: combo
 */

#include <bits/stdc++.h>
using namespace std;

inline bool close(int a, int b, int n) {
  return abs(a - b) <= 2 || abs(a - b) >= n - 2;
}

inline bool ok(const vector<int>& a, const vector<int>& b, int n) {
  for (int i = 0; i < 3; i++) {
    if (!close(a[i], b[i], n)) return false;
  }
  return true;
}

int main() {
  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> f(3), m(3);
  for (int& it : f) cin >> it;
  for (int& it : m) cin >> it;
  int result = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        const vector<int> c = { i, j, k };
        result += (int) (ok(f, c, n) || ok(m, c, n));
      }
    }
  }
  cout << result << '\n';
}
