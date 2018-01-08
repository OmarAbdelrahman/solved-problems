/*
ID: omar.se1
LANG: C++11
TASK: numtri
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() {
  T x;
  std::cin >> x;
  return x;
}

int main() {
  freopen("numtri.in", "r", stdin);
  freopen("numtri.out", "w", stdout);
  auto n = next<int>();
  vector<int> a(n, 0), b(n);
  for (int i = 0; i < n; i++) {
    b = a;
    for (int j = 0; j < i + 1; j++) {
      auto t = next<int>();
      if (j == 0) {
        a[j] = b[j] + t;
      } else {
        a[j] = max(b[j], b[j - 1]) + t;
      }
    }
  }
  cout << *max_element(begin(a), end(a)) << '\n';
}
