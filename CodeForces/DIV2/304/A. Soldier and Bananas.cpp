#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int k, n, w; cin >> k >> n >> w;
  for (int i = 1; i <= w; ++i) {
  	n -= i * k;
  }
  cout << (n >= 0 ? 0 : -n) << endl;
  return 0;
}