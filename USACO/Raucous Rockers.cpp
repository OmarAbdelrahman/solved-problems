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

int f(int cd, int song, int rem, int cap[MAX]) {
	if (cd >= m || song > n)
		return 0;
	int& ret = dp[cd][song][rem];
	ret = 0;
	for (int nextSong = song + 1; nextSong <= n; ++nextSong) {
		if (length[nextSong] <= cap[cd]) {
			cap[cd] -= length[nextSong];
			ret = max(ret, f(cd + 1, nextSong, cap[cd] - length[nextSong], cap) + 1);
			ret = max(ret, f(cd, nextSong, cap[cd] - length[nextSong], cap) + 1);
			cap[cd] += length[nextSong];
		}
	}
	return ret;
}

int main() {
	freopen("rockers.in", "r", stdin);
	freopen("rockers.out", "w", stdout);
	cin >> n >> t >> m;
	for (int a = 1; a <= n; ++a)
		cin >> length[a];
	int cap[MAX];
	for (int a = 0; a < m; ++a)
		cap[a] = t;
	cout << f(0, 0, t, cap) << endl;
	return 0;
}
