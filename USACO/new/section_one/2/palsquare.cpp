/*
ID: omar.se1
LANG: C++11
TASK: palsquare
 */

#include <bits/stdc++.h>
using namespace std;

inline bool palindrome(const string& s) {
  const int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    if (s[n - i - 1] != s[i]) {
      return false;
    }
  }
  return true;
}

inline string to_base(int n, int b) {
  if (n == 0) return "";
  return to_base(n / b, b) + "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % b];
}

int main() {
  freopen("palsquare.in", "r", stdin);
  freopen("palsquare.out", "w", stdout);
  int b;
  cin >> b;
  for (int n = 1; n <= 300; n++) {
    string value = to_base(n * n, b);
    if (palindrome(value)) {
      cout << to_base(n, b) << ' ' << value << '\n';
    }
  }
  return 0;
}
