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

void doit(const int n) {
  ostringstream sin;
  sin << n;
  string left = sin.str();
  string right = left.substr(0, left.length() - 1);
  reverse(begin(right), end(right));
  string total = left + right;
  print(stoi(total));
}

int main() {
  freopen("pprime.in", "r", stdin);
  freopen("pprime.out", "w", stdout);
  cin >> a >> b;
  for (int i = 5; i <= 11; i += 2) {
    print(i);
  }
  for (int i = 10; i < 10000; i++) {
    doit(i);
  }
}
