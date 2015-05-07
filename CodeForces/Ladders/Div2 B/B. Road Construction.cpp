#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;

  vector<int> indegree(n, 0);
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    ++indegree[a - 1];
    ++indegree[b - 1];
  }

  cout << n - 1 << endl;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] != 0) {
      continue;
    }
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
    break;
  }
  return 0;
}
