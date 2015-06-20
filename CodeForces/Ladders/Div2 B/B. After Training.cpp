#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<pair<int, int>> ps(m);
  for (int i = 0; i < m; ++i) {
    ps[i] = { abs((m + 1) - (i + 1) * 2), i + 1 };
  }
  sort(ps.begin(), ps.end());

  for (int i = 0; i < n; ++i) {
    cout << ps[i % m].second << "\n";
  }
  return 0;
}