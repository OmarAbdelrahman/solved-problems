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
    for (auto& elem : row) elem = io::next<T>();
    return row;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  const int n = io::next<int>();
  const int k = io::next<int>();
  const vector<int> ranks = io::next_array<int>(n);
  map<int, int> count;
  for (const int rank : ranks) {
    ++count[rank];
  }
  int result = 0;
  while (count[k] != n) {
    map<int, int> changed_count;
    for (auto p : count) {
      const int key = p.first;
      const int value = p.second;
      if (value > changed_count[key] && key != k) {
        --count[key];
        ++count[key + 1];
        ++changed_count[key + 1];
      }
    }
    ++result;
  }
  cout << result << endl;
  return 0;
}