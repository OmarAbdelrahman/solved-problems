#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n; cin >> n;

  vector<int> as(n);
  vector<int> gs(n);
  for (int i = 0; i < n; ++i) {
    cin >> as[i] >> gs[i];
  }

  int tas = accumulate(as.begin(), as.end(), 0);
  int tgs = 0;

  string result(n, 'A');
  for (int i = 0; i < n; ++i) {
    if (abs(tas - tgs) <= 500) {
      break;
    }
    tas -= as[i];
    tgs += gs[i];
    result[i] = 'G';
  }

  if (abs(tas - tgs) > 500) {
    cout << -1 << endl;
  } else {
    cout << result << endl;
  }
  return 0;
}
