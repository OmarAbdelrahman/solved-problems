#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  const string s = "abcd";

  for (int i = 0; i < n; ++i) {
    cout << s[i % 4];
  }
  return 0;
}
