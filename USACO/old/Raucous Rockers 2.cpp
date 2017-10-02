/*
ID: 1010
PROG: rockers
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

#define MAX 21

int n, t, m;
int length[MAX];
int dp[MAX][MAX * MAX + 2][MAX];

int f(int indx, int fill, int cdIndx) {
	if (indx >= n || cdIndx >= m)
		return 0;
	int& ret = dp[indx][fill][cdIndx];
	if (ret != -1) return ret;
	if (length[indx] + fill <= t) {
		int s1 = f(indx + 1, length[indx] + fill, cdIndx) + 1;
		int s2 = f(indx + 1, fill, cdIndx);
		return ret = max(s1, s2);
	} else if (length[indx] <= t && cdIndx + 1 < m) {
		int s1 = f(indx + 1, length[indx], cdIndx + 1) + 1;
		int s2 = f(indx + 1, fill, cdIndx);
		return ret = max(s1, s2);
	} else {
		return ret = f(indx + 1, fill, cdIndx);
	}
}

int main() {
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	cin >> n >> t >> m;
	for (int a = 0; a < n; ++a)
		cin >> length[a];
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0, 0) << endl;
	return 0;
}
