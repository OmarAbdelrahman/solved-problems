/*
ID: omar.se1
LANG: C++11
TASK: ride
 */

#include <bits/stdc++.h>
using namespace std;

inline int compute(const char* s) {
  const int n = strlen(s);
  int p = 1;
  for (int i = 0; i < n; i++) {
    p *= (s[i] - 'A' + 1);
    p %= 47;
  }
  return p;
}

int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);
  char s[10], t[10];
  scanf("%s", s);
  scanf("%s", t);
  if (compute(s) == compute(t)) {
    puts("GO");
  } else {
    puts("STAY");
  }
  return 0;
}
