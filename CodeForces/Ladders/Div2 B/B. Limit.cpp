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

  int n, m; cin >> n >> m;
  vector<int> a = io::next_array<int>(n + 1);
  vector<int> b = io::next_array<int>(m + 1);

  if (n < m) {
    cout << "0/1" << endl;
  } else if (n > m) {
    cout << (a[0] * b[0] < 0 ? "-" : "") << "Infinity" << endl;
  } else {
    const int g = __gcd(a[0], b[0]);
    cout << (a[0] * b[0] < 0 ? "-" : "") << abs(a[0] / g) << "/" << abs(b[0] / g) << endl;
  }
  return 0;
}