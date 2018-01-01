/*
ID: omar.se1
LANG: C++11
TASK: skidesign
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 17;

template<class T>
inline T next() {
  T x;
  std::cin >> x;
  return x;
}

int main() {
  freopen("skidesign.in", "r", stdin);
  freopen("skidesign.out", "w", stdout);
  vector<int> h(next<int>());
  for (int& it : h) cin >> it;
  int result = numeric_limits<int>::max();
  for (int low = 1; low <= 100 - M; low++) {
    int cost = 0;
    int high = low + M;
    for (const int& hill_height : h) {
      int tc = 0;
      if (hill_height < low) {
        tc = low - hill_height;
      } else if (hill_height > high) {
        tc = hill_height - high;
      }
      cost += tc * tc;
    }
    result = min(result, cost);
  }
  cout << result << '\n';
}
