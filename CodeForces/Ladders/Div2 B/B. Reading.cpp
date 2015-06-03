#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[1010];

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, k; cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }

  sort(a, a + n);

  cout << a[n - k].first << endl;
  for (int i = n - k; i < n; ++i) {
  	cout << a[i].second << " ";
  }
  return 0;
}