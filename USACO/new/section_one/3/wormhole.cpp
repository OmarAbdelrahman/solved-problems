/*
ID: omar.se1
LANG: C++11
TASK: wormhole
 */

#include <bits/stdc++.h>
using namespace std;

bool cycle(const vector<int>& parent, const vector<int>& next) {
  for (size_t i = 0; i < parent.size(); i++) {
    int pos = i;
    for (size_t _ = 0; _ < parent.size(); _++) {
      pos = next[parent[pos]];
      if (pos == -1) break;
    }
    if (pos != -1) return true;
  }
  return false;
}

int permute(vector<int>& parent, vector<int>& next) {
  auto it = find(begin(parent), end(parent), -1);
  if (it == end(parent)) {
    return cycle(parent, next) ? 1 : 0;
  }
  int total = 0;
  const int i = it - begin(parent);
  for (size_t j = i + 1; j < parent.size(); j++) {
    if (parent[j] == -1) {
      parent[i] = j;
      parent[j] = i;
      total += permute(parent, next);
      parent[i] = -1;
      parent[j] = -1;
    }
  }
  return total;
}

int main() {
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> parent(n, -1);
  vector<int> next(n, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (x[i] < x[j] && y[i] == y[j]) {
        if (next[i] == -1 || x[j] - x[i] < x[next[i]] - x[i]) {
          next[i] = j;
        }
      }
    }
  }
  cout << permute(parent, next) << '\n';
}
