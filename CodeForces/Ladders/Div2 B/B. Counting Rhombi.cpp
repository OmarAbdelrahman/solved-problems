#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int w, h; cin >> w >> h;
  long long result = 0;
  for (int rw = 2; rw <= w; rw += 2) {
    for (int rh = 2; rh <= h; rh += 2) {
      result += 1LL * (h - rh + 1) * (w - rw + 1);
    }
  }
  cout << result << endl;
  return 0;
}