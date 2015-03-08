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
  int m = io::next<int>();
  if (m == 0) {
    cout << "YES" << endl;
    return 0;
  }

  vector<int> dirty = io::next_array<int>(m);
  sort(dirty.begin(), dirty.end());
  if (dirty.front() == 1 || dirty.back() == n) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> ds;
  for (int i = 1; i < dirty.size(); ++i) {
    ds.push_back(dirty[i] - dirty[i - 1]);
  }

  int count = 0;
  for (const int d : ds) {
    if (d == 1) {
      ++count;
      if (count == 2) {
        cout << "NO" << endl;
        return 0;
      }
    } else {
      count = 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}
