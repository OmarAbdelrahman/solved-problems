/*
ID: omar.se1
LANG: C++11
TASK: milk3
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 22;

array<array<array<bool, M>, M>, M> visited;
array<bool, M> valid;

void solve(int a, int b, int c, const int& A, const int& B, const int& C) {
  if (visited[a][b][c]) return;
  visited[a][b][c] = true;
  if (a == 0) {
    valid[c] = true;
  }
  int rem_a = max(0, A - a);
  int rem_b = max(0, B - b);
  int rem_c = max(0, C - c);
  // c -> b
  solve(a, c >= rem_b ? B : b + c, c >= rem_b ? c - rem_b : 0, A, B, C);
  // c -> a
  solve(c >= rem_a ? A : a + c, b, c >= rem_a ? c - rem_a : 0, A, B, C);
  // b -> a
  solve(b >= rem_a ? A : a + b, b >= rem_a ? b - rem_a : 0, c, A, B, C);
  // b -> c
  solve(a, b >= rem_c ? b - rem_c : 0, b >= rem_c ? C : c + b, A, B, C);
  // a -> b
  solve(a >= rem_b ? a - rem_b : 0, a >= rem_b ? B : b + a, c, A, B, C);
  // a -> c
  solve(a >= rem_c ? a - rem_c : 0, b, a >= rem_c ? C : c + a, A, B, C);
}

int main() {
  freopen("milk3.in", "r", stdin);
  freopen("milk3.out", "w", stdout);
  int cap_a, cap_b, cap_c;
  cin >> cap_a >> cap_b >> cap_c;
  solve(0, 0, cap_c, cap_a, cap_b, cap_c);
  bool first = true;
  for (int i = 0; i <= 20; i++) {
    if (valid[i]) {
      if (!first) cout << ' ';
      cout << i;
      first = false;
    }
  }
  cout << '\n';
}
