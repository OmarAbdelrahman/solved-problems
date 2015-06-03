#include <bits/stdc++.h>
using namespace std;

int d[110];
vector<int> g[110];

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    --a, --b;

    ++d[a], ++d[b];
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int result = 0;
  while (true) {
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      if (d[i] == 1) {
        s.push_back(i);
      }
    }
    if (s.empty()) {
      break;
    }
    for (int v : s) {
      --d[v];
      for (int nv : g[v]) {
        --d[nv];
      }
    }
    ++result;
  }
  cout << result;
  return 0;
}