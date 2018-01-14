/*
ID: omar.se1
LANG: C++11
TASK: sprime
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() {
  T x;
  std::cin >> x;
  return x;
}

bool prime(const int n) {
  if (n == 2) return true;
  if (n <= 1 || n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void compute(const int val, const int n) {
  if (n == 0) {
    cout << val << '\n';
  } else {
    for (int i = 1; i < 10; i++) {
      const int next = val * 10 + i;
      if (prime(next)) {
        compute(next, n - 1);
      }
    }
  }
}

int main() {
  freopen("sprime.in", "r", stdin);
  freopen("sprime.out", "w", stdout);
  auto n = next<int>();
  for (int i = 2; i < 10; i++) {
    if (prime(i)) {
      compute(i, n - 1);
    }
  }
}
