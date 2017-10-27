/*
ID: omar.se1
LANG: C++11
TASK: milk2
 */

#include <bits/stdc++.h>
using namespace std;

struct interval_type {
  int s;
  int e;

  bool operator < (const interval_type& i) const {
    if (s != i.s) {
      return s < i.s;
    }
    return e < i.e;
  }

  bool overlaps(const interval_type& other) {
    return contains(other.s) || contains(other.e);
  }

  bool contains(int i) {
    return i >= s && i <= e;
  }
};

interval_type farmer[5555];

int main() {
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &farmer[i].s, &farmer[i].e);
  }
  sort(farmer, farmer + n);
  int max_milking = farmer[0].e - farmer[0].s;
  int max_empty = 0;
  interval_type border = farmer[0];
  for (int i = 1; i < n; i++) {
    if (border.overlaps(farmer[i])) {
      if (farmer[i].e > border.e) {
        border.e = farmer[i].e;
      }
      max_milking = max(max_milking, border.e - border.s);
    } else {
      max_empty = max(max_empty, farmer[i].s - border.e);
      border = farmer[i];
    }
  }
  printf("%d %d\n", max_milking, max_empty);
  return 0;
}
