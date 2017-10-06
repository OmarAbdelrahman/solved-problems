/*
ID: omar.se1
LANG: C++11
TASK: beads
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 355;

int n;
char necklace[M];
char b_necklace[M];
char r_necklace[M];

int compute(int si, const char* beads, int direction) {
  int count = 1;
  char color = beads[si];
  int i = (si + direction + n) % n;
  while (i != si && beads[i] == color) {
    i = (i + direction + n) % n;
    count++;
  }
  return count;
}

int main() {
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  scanf("%d", &n);
  scanf("%s", necklace);
  for (int i = 0; i < n; i++) {
    b_necklace[i] = necklace[i];
    r_necklace[i] = necklace[i];
    if (necklace[i] == 'w') {
      b_necklace[i] = 'b';
      r_necklace[i] = 'r';
    }
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    int fi = (i + 1) % n;
    int c1 = max(compute(i, b_necklace, -1), compute(i, r_necklace, -1));
    int c2 = max(compute(fi, b_necklace, 1), compute(fi, r_necklace, 1));
    result = max(result, c1 + c2);
  }
  if (result > n) {
    result = n;
  }
  printf("%d\n", result);
  return 0;
}
