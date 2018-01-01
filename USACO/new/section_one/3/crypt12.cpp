/*
ID: omar.se1
LANG: C++11
TASK: crypt1
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() {
  T x;
  cin >> x;
  return x;
}

array<bool, 10> digit;

bool digits_okay(int n, int len) {
  while (n > 0) {
    if (!digit[n % 10]) return false;
    n /= 10;
    len--;
  }
  return len == 0;
}

bool ok(int u, int d) {
  if (!digits_okay(u, 3) || !digits_okay(d, 2) || !digits_okay(u * d, 4)) {
    return false;
  }
  while (d > 0) {
    if (!digits_okay(u * (d % 10), 3)) {
      return false;
    }
    d /= 10;
  }
  return true;
}

int main() {
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);
  auto n = next<int>();
  for (int i = 0; i < n; i++) {
    digit[next<int>()] = true;
  }
  int result = 0;
  for (int u = 100; u < 1000; u++) {
    for (int d = 10; d < 100; d++) {
      result += (int) ok(u, d);
    }
  }
  cout << result << '\n';
}
