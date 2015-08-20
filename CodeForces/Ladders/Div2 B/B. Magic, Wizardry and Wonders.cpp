#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, diff, l; cin >> n >> diff >> l;
  vector<int> result(n);
  if (n % 2 == 1) {
    result[n - 1] = min(l, max(1, diff));
    diff -= result[n - 1];
  }
  for (int i = 0; i + 1 < n; i += 2) {
    if (diff > 0) {
      result[i] = min(l, diff + 1);
      result[i + 1] = 1;
      diff -= result[i] - 1;
    } else {
      result[i] = 1;
      result[i + 1] = min(-diff + 1, l);
      diff += result[i + 1] - 1;
    }
  }
  if (diff == 0) {
    for (int x : result) cout << x << " ";
    cout << endl;
  } else {
  	cout << -1 << endl;
  }
  return 0;
}