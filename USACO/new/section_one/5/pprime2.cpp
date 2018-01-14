/*
ID: omar.se1
LANG: C++11
TASK: pprime
 */

#include <bits/stdc++.h>
using namespace std;

int a, b;

template<class T>
inline T next() {
  T x;
  std::cin >> x;
  return x;
}

inline bool in_range(const int n) {
  return n >= a && n <= b;
}

inline bool prime(const int n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void print(const int d) {
  if (in_range(d) && prime(d)) {
    cout << d << '\n';
  }
}

void compute(const int digits, const int val, const int tens_left, const int tens_right, const bool outer) {
  if (digits == 1) {
    assert(tens_left == tens_right);
    for (int i = 0; i < 10; i++) {
      print(val + tens_left * i);
    }
  } else {
    for (int i = (int) outer; i < 10; i += (1 + (int) outer)) {
      compute(digits - 2, val + tens_left * i + tens_right * i, tens_left / 10, tens_right * 10, false);
    }
  }
}

int main() {
  freopen("pprime.in", "r", stdin);
  freopen("pprime.out", "w", stdout);
  cin >> a >> b;
  for (int i = 5; i <= 11; i += 2) {
    print(i);
  }
  for (int i = 3; i <= 7; i += 2) {
    compute(i, 0, (int) pow(10, i - 1), 1, true);
  }
}
