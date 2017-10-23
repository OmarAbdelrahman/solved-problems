/*
ID: omar.se1
LANG: C++11
TASK: milk2
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 5555;

struct interval_type {
  int s;
  int e;

  bool operator < (const interval_type& i) {
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

vector<interval_type> farmer;

int continous_milking(int& si, int n) {
  int i = si;
  while (farmer[si - 1].overlaps(farmer[si]) && si + 1 < n) {
    si++;
  }
  return farmer[si].e - farmer[i].s;
}

int continous_empty(int& si, int n) {
  int i = si;
  while (!farmer[si - 1].overlaps(farmer[si]) && si + 1 < n) {
    si++;
  }
  return farmer[si].s - farmer[i].e;
}

int main() {
  // freopen("milk2.in", "r", stdin);
  // freopen("milk2.out", "w", stdout);
  int n;
  scanf("%d", &n);
  interval.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &farmer[i].s, &farmer[i].e);
  }
  sort(farmer.begin(), farmer.end());
  int max_milking = farmer[0].e - farmer[0].s;
  int max_empty = 0;
  for (int i = 1; i < n; i++) {
    max_milking = max(max_milking, continous_milking(i, n));
  }
  for (int i = 1; i < n; i++) {
    max_empty = max(max_empty, continous_empty(i, n));
  }
  printf("%d %d\n", max_milking, max_empty);
  return 0;
}
