#include <bits/stdc++.h>
using namespace std;

int parent[111];
int size[111];

int parent_set(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = parent_set(parent[x]);
}

bool join(int a, int b) {
  const int x = parent_set(a);
  const int y = parent_set(b);
  if (x == y) {
    return false;
  }
  parent[y] = x;
  size[x] += size[y];
  return true;
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    parent[i] = i;
    size[i] = 1;
  }
  int result = 0;
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    --a, --b;
    if (!join(a, b)) {
      const int ps = size[parent_set(a)];
      if (ps != 1 && ps % 2 != 0) {
        ++result;
      }
    }
  }
  if ((n - result) % 2 != 0) {
    ++result;
  }
  cout << result << endl;
  return 0;
}