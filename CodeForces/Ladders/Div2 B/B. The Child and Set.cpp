#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int t, n; cin >> t >> n;

  vector<int> result;
  for (int i = n; i >= 1; --i) {
  	int lsb = i & -i;
  	if (t - lsb >= 0) {
  		result.push_back(i);
  		t -= lsb;
  	}
  }

  if (t > 0) {
  	cout << -1;
  } else {
  	cout << result.size() << endl;
  	for (int v : result) {
  		cout << v << " ";
  	}
  }
  return 0;
}