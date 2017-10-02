/*
ID: omar.se1
LANG: C++11
TASK: ride
 */

#include <bits/stdc++.h>
using namespace std;

char s[10];
char t[10];

int main() {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);
  scanf("%s", s);
  scanf("%s", t);
  int n = strlen(s);
  int m = strlen(t);
  int sp = 1;
  for (int i = 0; i < n; i++) {
  	sp *= (s[i] - 'A' + 1);
  	sp %= 47;
  }
  int tp = 1;
  for (int i = 0; i < m; i++) {
  	tp *= (t[i] - 'A' + 1);
  	tp %= 47;
  }
  if (sp == tp) {
  	puts("GO");
  } else {
  	puts("STAY");
  }
  return 0;
}
