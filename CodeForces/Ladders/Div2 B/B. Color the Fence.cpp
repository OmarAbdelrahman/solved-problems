#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int v; cin >> v;
  int costs[10];
  for (int i = 1; i <= 9; ++i) {
    cin >> costs[i];
  }

  int m = *min_element(costs + 1, costs + 1 + 9);
  if (m > v) {
    cout << -1 << endl;
    return 0;
  }

  int len = v / m;
  v -= len * m;

  for (int i = 0; i < len; ++i) {
    for (int d = 9; d >= 1; --d) {
      if (costs[d] - m <= v) {
        v -= costs[d] - m;
        cout << d;
        break;
      }
    }
  }
  cout << endl;
  return 0;
}