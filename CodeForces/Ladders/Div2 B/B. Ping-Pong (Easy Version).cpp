#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

bool solve(const int a, const int b, const vector<pair<int, int>>& ps) {
  const int n = ps.size();
  vector<vector<bool>> can(n, vector<bool>(n, false));

  for (int i = 0; i < n; ++i) {
    can[i][i] = true;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }
      int a, b, c, d;
      tie(a, b) = make_tuple(ps[i].first, ps[i].second);
      tie(c, d) = make_tuple(ps[j].first, ps[j].second);
      if ((c < a && a < d) || (c < b && b < d)) {
        can[i][j] = true;
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        can[i][j] = can[i][j] | (can[i][k] & can[k][j]);
      }
    }
  }
  return can[a - 1][b - 1];
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int q; cin >> q;
  vector<pair<int, int>> ps;
  while (q-- > 0) {
    int c, a, b; cin >> c >> a >> b;
    if (c == 1) {
      ps.push_back({ a, b });
    } else {
      cout << (solve(a, b, ps) ? "YES" : "NO") << "\n";
    }
  }
  return 0;
}