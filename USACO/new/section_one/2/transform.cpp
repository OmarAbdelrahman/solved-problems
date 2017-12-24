/*
ID: omar.se1
LANG: C++11
TASK: transform
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> rotate_clock_wise(const vector<string>& b) {
	const int n = b.size();
	vector<string> a(n, string(n, ' '));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = b[n - j - 1][i];
		}
	}
	return a;
}

vector<string> reflect(const vector<string>& b) {
	const int n = b.size();
	vector<string> a = b;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			swap(a[j][i], a[j][n - i - 1]);
		}
	}
	return a;
}

int solve(const vector<string>& b, const vector<string>& t) {
	const vector<string>& _90 = rotate_clock_wise(b);
	if (_90 == t) {
		return 1;
	}
	const vector<string>& _180 = rotate_clock_wise(_90);
	if (_180 == t) {
		return 2;
	}
	const vector<string>& _270 = rotate_clock_wise(_180);
	if (_270 == t) {
		return 3;
	}
	const vector<string>& reflection = reflect(b);
	if (reflection == t) {
		return 4;
	}
	const vector<string>& reflect90 = rotate_clock_wise(reflection);
	const vector<string>& reflect180 = rotate_clock_wise(reflect90);
	const vector<string>& reflect270 = rotate_clock_wise(reflect180);
	if (reflect90 == t || reflect180 == t || reflect270 == t) {
		return 5;
	}
	if (b == t) {
		return 6;
	}
	return 7;
}

int main() {
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);
  int n;
  scanf("%d", &n);
  vector<string> b(n), t(n);
  for (string& it : b) cin >> it;
  for (string& it : t) cin >> it;
  cout << solve(b, t) << '\n';
  return 0;
}
