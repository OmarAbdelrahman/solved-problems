#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
  }

  template<class T>
  static inline std::vector<T> next_array(const int n) {
    std::vector<T> row(n);
    for (auto& elem : row) elem = io::next<T>();
    return row;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  const int n = io::next<int>();
  const vector<int> a = io::next_array<int>(n);
  vector<int> c(10, 0);

  int total = 0;
  for (int x : a) {
    total += x;
    ++c[x];
  }
  if (total % 3 != 0) {
    for (int digit = 1; digit < 10; ++digit) {
      if (total % 3 == digit % 3 && c[digit] > 0) {
        --c[digit];
        total -= digit;
        break;
      }
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int digit = 1; digit < 10; ++digit) {
      if (total % 3 != 0 && digit % 3 != 0 && c[digit] > 0) {
        --c[digit];
        total -= digit;
        break;
      }
    }
  }
  if (c[0] == 0 || total % 3 != 0) {
    cout << -1;
  } else {
    if (total == 0) {
      c[0] = 1;
    }
    for (int digit = 9; digit >= 0; --digit) {
      while (c[digit]-- > 0) {
        cout << digit;
      }
    }
  }
  return 0;
}