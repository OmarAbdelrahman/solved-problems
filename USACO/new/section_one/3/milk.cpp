/*
ID: omar.se1
LANG: C++11
TASK: milk
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("milk.in", "r", stdin);
  freopen("milk.out", "w", stdout);
  int u, fs;
  cin >> u >> fs;
  map<int, long long> prices;
  for (int i = 0; i < fs; i++) {
    int p, au;
    cin >> p >> au;
    prices[p] += au;
  }
  int result = 0;
  for (const auto& p : prices) {
    const int& price = p.first;
    const int& units = p.second;
    if (units <= u) {
      result += price * units;
      u -= units;
    } else {
      result += price * u;
      break;
    }
  }
  cout << result << '\n';
}
