/*
ID: omar.se1
LANG: C++11
TASK: barn1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("barn1.in", "r", stdin);
  freopen("barn1.out", "w", stdout);
  int b, s, c;
  cin >> b >> s >> c;
  vector<int> stalls(c);
  for (int& it : stalls) cin >> it;
  sort(begin(stalls), end(stalls));
  vector<int> gaps;
  for (int i = 1; i < c; i++) {
    if (stalls[i] - stalls[i - 1] > 1) {
      gaps.emplace_back(stalls[i] - stalls[i - 1] - 1);
    }
  }
  sort(begin(gaps), end(gaps), greater<int>());
  int bn = 1;
  int count = stalls.back() - stalls.front() + 1;
  int i = 0;
  while (bn < b && i < (int) gaps.size()) {
    count -= gaps[i++];
    bn++;
  }
  cout << count << '\n';
}
