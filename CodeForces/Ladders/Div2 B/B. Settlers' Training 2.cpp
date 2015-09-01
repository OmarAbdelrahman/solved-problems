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
  const int k = io::next<int>();
  vector<int> ranks = io::next_array<int>(n);
  ranks.push_back(k);
  int result = 0;
  while (ranks[0] < k) {
    for (int i = 0; i < n; ++i) {
      if (ranks[i] == k) {
        break;
      }
      if (ranks[i] == ranks[i + 1]) {
        continue;
      }
      ++ranks[i];
    }
    ++result;
  }
  cout << result << endl;
  return 0;
}