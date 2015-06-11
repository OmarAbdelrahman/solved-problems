#include <bits/stdc++.h>
using namespace std;

long long s(long long x) {
  return x > 0 ? (x % 10) + s(x / 10) : 0;
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  long long n; cin >> n;
  long long result = numeric_limits<long long>::max();
  for (int sx = 1; sx < 100; ++sx) {
    long long v = sx * sx + 4 * n;
    if (v < 0) {
      continue;
    }
    long long root = (long long) sqrt(v);
    if (root * root != v) {
      continue;
    }
    long long x1 = (-sx + root) / 2;
    long long x2 = (-sx - root) / 2;
    if (x1 >= 0) {
      if (s(x1) == sx) {
        result = min(result, x1);
      }
    }
    if (x2 >= 0) {
      if (s(x2) == sx) {
        result = min(result, x2);
      }
    }
  }

  cout << (result == numeric_limits<long long>::max() ? -1 : result) << endl;
  return 0;
}
