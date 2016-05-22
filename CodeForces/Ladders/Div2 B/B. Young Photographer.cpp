#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, s; cin >> n >> s;
  int left_most = 1234;
  int right_most = -1;

  vector<int> as, bs;
  for (int i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    as.push_back(a);
    bs.push_back(b);

    left_most = min(left_most, a);
    right_most = max(right_most, b);
  }

  int closest = 1234;
  for (int i = left_most; i <= right_most; ++i) {
    int vcount = 0;
    vector<bool> visited(n, false);
    for (int j = 0; j < n; ++j) {
      if (!visited[j] && as[j] <= i && i <= bs[j]) {
        visited[j] = true;
        ++vcount;
      }
    }
    if (vcount == n) {
      closest = min(closest, abs(i - s));
    }
  }
  if (closest == 1234) {
    cout << -1 << endl;
  } else {
    cout << closest << endl;
  }
  return 0;
}
