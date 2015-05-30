#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, k; cin >> n >> k;

  if (k == n) {
    cout << -1 << endl;
  } else {
    int d = n - k;

    cout << d;
    for (int i = 1; i <= n; ++i) {
      if (i != d) {
        cout << " " << i;
      }
    }
  }
  return 0;
}