#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  double x, y, n; cin >> x >> y >> n;
  int a = 0, b = 1;
  double diff = 10e9;
  for (int q = 1; q <= n; ++q) {
    int p = round((q / y) * x - 1e-7);
    double d = abs((double) p / (double) q - x / y);
    if (d < diff) {
      diff = d;
      a = p, b = q;
    }
  }
  cout << a << "/" << b << endl;
  return 0;
}