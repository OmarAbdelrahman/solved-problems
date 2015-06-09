#include <bits/stdc++.h>
using namespace std;

bool ok(int x, int y, int n, int m) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;

  vector<string> g(n);
  for (string& s : g) {
    cin >> s;
  }

  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!ok(i + 1, j, n, m) || !ok(i, j + 1, n, m) || !ok(i + 1, j + 1, n, m)) {
        continue;
      }
      string word = "";
      word += g[i][j];
      word += g[i + 1][j];
      word += g[i][j + 1];
      word += g[i + 1][j + 1];

      sort(word.begin(), word.end());
      if (word == "acef") {
        ++result;
      }
    }
  }

  cout << result;
  return 0;
}