#include <bits/stdc++.h>
using namespace std;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
  }

  template<class T, typename Fun>
  static inline T next(Fun f) {
    T x; std::cin >> x;
    return f(x);
  }

  template<class T>
  static inline std::vector<T> next_array(const int n) {
    std::vector<T> row(n);
    for (int i = 0; i < n; ++i)
      row[i] = io::next<T>();
    return row;
  }

  template<class T, typename Fun>
  static inline std::vector<T> next_array(const int n, Fun f) {
    std::vector<T> row(n);
    for (int i = 0; i < n; ++i)
      row[i] = io::next<T>(f);
    return row;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  auto f = [](const int x) {
    return x - 1;
  };

  const int n = io::next<int>();
  const int s = io::next<int>(f);
  const int t = io::next<int>(f);
  
  vector<int> p = io::next_array<int>(n, f);
  vector<vector<int>> g(n);

  for (int i = 0; i < n; ++i) {
    g[i].push_back(p[i]);
  }

  unordered_set<int> visited;
  queue<pair<int, int>> q;

  visited.insert(s);
  for (q.push({ s, 0 }); !q.empty(); q.pop()) {
    const int now = q.front().first;
    const int cost = q.front().second;

    if (now == t) {
      cout << cost << endl;
      return 0;
    }
    for (const int next : g[now]) {
      if (visited.find(next) == visited.end()) {
        q.push({ next, cost + 1 });
        visited.insert(next);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
