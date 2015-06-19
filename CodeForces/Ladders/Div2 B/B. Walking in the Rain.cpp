#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int a[1010];

bool can(int ai, int sz) {
  if (ai > a[0]) {
    return false;
  }
  vector<bool> cn(sz, false);
  cn[0] = true;
  for (int i = 0; i < sz; ++i) {
    if (cn[i]) {
      if (i + 1 < sz && a[i + 1] >= ai) {
        cn[i + 1] = true;
      }
      if (i + 2 < sz && a[i + 2] >= ai) {
        cn[i + 2] = true;
      }
    }
  }
  return cn[sz - 1];
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int b = 0;
  int e = 1000;
  while (e - b > 1) {
    int m = (b + e) >> 1;
    if (can(m, n)) {
      b = m;
    } else {
      e = m;
    }
  }
  cout << b << "\n";
  return 0;
}