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

inline int n_size(int n) {
  int c = 0;
  for (; n > 0; n /= 10, c++);
  return c;
}

inline bool digits_in_set(int n, const set<int>& s) {
  while (n > 0) {
    if (s.find(n % 10) == end(s)) return false;
    n /=  10;
  }
  return true;
}

inline bool ok_partial_product(const int p, const set<int>& s) {
  return n_size(p) == 3 && digits_in_set(p, s);
}

inline bool ok_final_product(const int p, const set<int>& s) {
  return n_size(p) == 4 && digits_in_set(p, s);
}

int main() {
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);
  auto n = next<int>();
  set<int> digits;
  for (int i = 0; i < n; i++) {
    digits.insert(next<int>());
  }
  int result = 0;
  for (const int a : digits)
    for (const int b : digits)
      for (const int c : digits)
        for (const int d : digits)
          for (const int e : digits) {
            const int u = a * 100 + b * 10 + c;
            const int p1 = u * e;
            const int p2 = u * d;
            if (ok_partial_product(p1, digits) && ok_partial_product(p2, digits)) {
              result += (int) ok_final_product(p1 + p2 * 10, digits);
            }
          }
  cout << result << '\n';
}
