/*
ID: 1010
PROG: game1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

#define MAX 202

int n, seq[MAX];
pair<int, int> dp[MAX][MAX];

pair<int, int> f(int s, int e, bool first) {
	if (s > e) return make_pair(0, 0);
	pair<int, int>& ret = dp[s][e];
	if (ret.first != -1) {
		return ret;
	}
	if (first) {
		pair<int, int> s1 = f(s + 1, e, !first);
		pair<int, int> s2 = f(s, e - 1, !first);
		s1.first += seq[s];
		s2.first += seq[e];
		ret = s1.first > s2.first ? s1 : s2;
	} else {
		pair<int, int> s1 = f(s + 1, e, !first);
		pair<int, int> s2 = f(s, e - 1, !first);
		s1.second += seq[s];
		s2.second += seq[e];
		ret = s1.second > s2.second ? s1 : s2;
	}
	return ret;
}

inline pair<int, int> _main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			dp[i][j] = make_pair(-1, -1);
	return f(0, n - 1, true);
}

int main() {
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	pair<int, int> res = _main();
	printf("%d %d\n", res.first, res.second);
	return 0;
}
