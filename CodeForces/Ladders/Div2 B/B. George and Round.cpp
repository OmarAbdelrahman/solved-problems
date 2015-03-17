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
    for (auto& x : row) x = io::next<T>();
    return row;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  const int n = io::next<int>();
  const int m = io::next<int>();

  vector<int> ns = io::next_array<int>(n);
  vector<int> ps = io::next_array<int>(m);

  int added = 0;
  while (ps.size() < ns.size()) {
    ps.push_back(10000001);
    ++added;
  }
 
  int i = 0;
  for (const int p : ps) if (p >= ns[i] && i != ns.size()) ++i;

  cout << added + (int) ns.size() - i << endl; 
  return 0;
}
