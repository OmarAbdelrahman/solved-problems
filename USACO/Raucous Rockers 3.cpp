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
int dp[MAX][MAX][MAX];

int f(int cd, int song, int cap) {
	if (cd >= m || song >= n || cap > t)
		return 0;
	int& ret = dp[cd][song][cap];
	if (ret != -1) return ret;
	ret = 0;
	int s1 = -1;
	if (cap + length[song] <= t)
		s1 = f(cd, song + 1, cap + length[song]) + 1;
	int s2 = f(cd, song + 1, cap);
	int s3 = f(cd + 1, song, 0);
	return ret = max(s1, max(s2, s3));
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
