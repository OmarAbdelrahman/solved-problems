#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  string n; cin >> n;
  long long result = 1;
  for (int i = 0; i + 1 < n.length(); ++i) {
    const int a = n[i + 0] - '0';
    const int b = n[i + 1] - '0';
    if (a + b != 9) {
      continue;
    }
    long long size = 2;
    int j = i + 1;
    for (; j + 1 < n.length(); ++j) {
      const int ta = n[j + 0] - '0';
      const int tb = n[j + 1] - '0';
      if (ta + tb == 9) ++size; else break;
    }
    i = j - 1;
    if (size % 2 != 0) {
      result *= (size / 2 + 1);
    }
  }
  cout << result << endl;
  return 0;
}
