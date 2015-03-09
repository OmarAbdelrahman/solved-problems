#include <bits/stdc++.h>
using namespace std;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
  }

  template<class T>
  static inline std::vector<T> next_array(const int n) {
    std::vector<T> row(n);
    for (int i = 0; i < n; ++i)
      row[i] = io::next<T>();
    return row;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n = io::next<int>();
  int t = io::next<int>();
  vector<int> as = io::next_array<int>(n);
  
  int j = 0;
  int result = 0;
  for (int i = 0; i < n; ++i) {
    while (j < n && as[j] <= t) {
      t -= as[j++];
    }
    result = max(result, j - i);
    if (j == n) break;
    t += as[i];
  }
  
  cout << result << endl;
  return 0;
}
