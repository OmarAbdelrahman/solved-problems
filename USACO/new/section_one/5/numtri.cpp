/*
ID: omar.se1
LANG: C++11
TASK: numtri
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() {
  T x;
  std::cin >> x;
  return x;
}

int main() {
  freopen("numtri.in", "r", stdin);
  freopen("numtri.out", "w", stdout);
  vector<vector<int>> g(next<size_t>());
  for (size_t i = 0; i < g.size(); i++) {
    for (size_t j = 0; j < i + 1; j++) {
      g[i].push_back(next<int>());
    }
  }
  for (size_t i = 1; i < g.size(); i++) {
    for (size_t j = 0; j < g[i].size(); j++) {
      if (j == 0) {
        g[i][j] += g[i - 1][j];
      } else {
        g[i][j] += max(j == g[i - 1].size() ? 0 : g[i - 1][j], g[i - 1][j - 1]);
      }
    }
  }
  cout << *max_element(begin(g.back()), end(g.back())) << '\n';
}
