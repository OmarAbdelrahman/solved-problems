/*
ID: omar.se1
LANG: C++11
TASK: dualpal
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
  freopen("dualpal.in", "r", stdin);
  freopen("dualpal.out", "w", stdout);
  int n, s;
  cin >> n >> s;
  for (int p = s + 1; n > 0; p++) {
    int cnt = 2;
    for (int b = 2; b <= 10 && cnt > 0; b++) {
      cnt -= (int) palindrome(to_base(p, b));
    }
    if (cnt == 0) {
      cout << p << '\n';
      n--;
    }
  }
}
