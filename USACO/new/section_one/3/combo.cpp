/*
ID: omar.se1
LANG: C++11
TASK: combo
 */

#include <bits/stdc++.h>
using namespace std;

inline bool in(int& a, int n) {
  if (a < 1) a += n;
  if (a > n) a -= n;
  return 1 <= a && a <= n;
}

set<tuple<int, int, int>> unlocked_combinations(int a, int b, int c, int n) {
  set<tuple<int, int, int>> s;
  for (int i = a - 2; i <= a + 2; i++) {
    for (int j = b - 2; j <= b + 2; j++) {
      for (int k = c - 2; k <= c + 2; k++) {
        int d, e, f;
        tie(d, e, f) = make_tuple(i, j, k);
        if (in(d, n) && in(e, n) && in(f, n)) {
          s.insert(make_tuple(d, e, f));
        }
      }
    }
  }
  return s; 
}

int main() {
  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);
  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;
  int d, e, f;
  cin >> d >> e >> f;
  set<tuple<int, int, int>> farmer = unlocked_combinations(a, b, c, n);
  set<tuple<int, int, int>> master = unlocked_combinations(d, e, f, n);
  master.insert(begin(farmer), end(farmer));
  cout << master.size() << '\n';
}
