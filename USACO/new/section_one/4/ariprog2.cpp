/*
ID: omar.se1
LANG: C++11
TASK: ariprog
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 125001;

array<bool, M> bisquare;

bool solve(int start, int diff, int depth) {
  if (depth <= 0) return true;
  bool found = false;
  if (start + diff <= M && bisquare[start + diff]) {
    found |= solve(start + diff, diff, depth - 1);
  } else {
    return false;
  }
  return found;
}

int main() {
  freopen("ariprog.in", "r", stdin);
  freopen("ariprog.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int p = 0; p <= m; p++) {
    for (int q = 0; q <= m; q++) {
      bisquare[p * p + q * q] = true;
    }
  }
  bool at_least_one = false;
  for (int diff = 1; diff <= 5000; diff++) {
    for (int i = 0; i < M; i++) {
      if (!bisquare[i]) continue;
      if (solve(i, diff, n - 1)) {
        cout << i << ' ' << diff << '\n';
        at_least_one = true;
      }
    }
  }
  if (!at_least_one) puts("NONE");
}
