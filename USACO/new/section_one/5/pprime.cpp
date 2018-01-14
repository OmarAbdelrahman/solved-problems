/*
ID: omar.se1
LANG: C++11
TASK: pprime
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() {
  T x;
  std::cin >> x;
  return x;
}

inline bool in_range(const int a, const int b, const int n) {
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

void print(const int a, const int b, const int d) {
  if (in_range(a, b, d) && prime(d)) {
    cout << d << '\n';
  }
}

int main() {
  freopen("pprime.in", "r", stdin);
  freopen("pprime.out", "w", stdout);
  int a, b;
  cin >> a >> b;
  for (int i = 5; i < 10; i += 2) {
    print(a, b, i);
  }
  for (int i = 1; i < 10; i += 2) {
    print(a, b, i * 10 + i);
  }
  for (int i = 1; i < 10; i += 2) {
    for (int j = 0; j < 10; j++) {
      print(a, b, i * 100 + j * 10 + i);
    }
  }
  for (int i = 1; i < 10; i += 2) {
    for (int j = 0; j < 10; j++) {
      print(a, b, i * 1000 + j * 100 + j * 10 + i);
    }
  }
  for (int i = 1; i < 10; i += 2) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        print(a, b, i * 10000 + j * 1000 + k * 100 + j * 10 + i);
      }
    }
  }
  for (int i = 1; i < 10; i += 2) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        print(a, b, i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i);
      }
    }
  }
  for (int i = 1; i < 10; i += 2) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          print(a, b, i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i);
        }
      }
    }
  }
  for (int i = 1; i < 10; i += 2) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          print(a, b, i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l * 1000 + k * 100 + j * 10 + i);
        }
      }
    }
  }
}
