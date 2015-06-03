#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    const int a = 2 * i - 1;
    const int b = 2 * i;

    if (i <= k) {
      cout << b << " " << a << " ";
    } else {
      cout << a << " " << b << " ";
    }
  }  
  return 0;
}