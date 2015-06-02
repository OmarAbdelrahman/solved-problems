#include <bits/stdc++.h>
using namespace std;

int a[2010];

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int d, n; cin >> d >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int result = 0;
  for (int i = 0; i < n - 1; ++i) {
    const int watch = a[i] + 1;
    const int clicks = (d - watch) + 1;
    result += clicks;
  }
  cout << result << endl;
  return 0;
}