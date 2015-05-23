#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  unordered_map<int, int> count;
  for (int x : a) count[x]++;

  int result = 0;
  for (int x : a) {
    while (count[x] > 1) {
      for (int i = x + 1;; ++i) {
        if (count[i] == 0) {
          count[i] = 1;
          result += (i - x);
          break;
        }
      }
      --count[x];
    }
  }

  cout << result << endl;
  return 0;
}
