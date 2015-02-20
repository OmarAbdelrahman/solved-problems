/*
ID: 1010
PROG: game1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

#define MAX 1002

int seq[MAX];
pair<int, int> dp[MAX][MAX];

pair<int, int> f(int s, int e, bool first) {
	if (s > e) return make_pair(0, 0);
	pair<int, int>& ret = dp[s][e];
	if (ret.first != -1) return ret;
	if (first) {
		pair<int, int> s1 = f(s + 1, e, !first);
		pair<int, int> s2 = f(s, e - 1, !first);
		s1.first += seq[s];
		s2.first += seq[e];
		ret = s1.first > s2.first ? s1 : s2;
	} else {
		pair<int, int> now;
		if (seq[s] > seq[e] || seq[s] == seq[e]) {
			now = f(s + 1, e, !first);
			now.second += seq[s];
		} else if (seq[s] < seq[e]) {
			now = f(s, e - 1, !first);
			now.second += seq[e];
		}
		ret = now;
	}
	return ret;
}

int _main(int n) {
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			dp[i][j] = make_pair(-1, -1);
	pair<int, int> res = f(0, n - 1, true);
	return res.second - res.first;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	int n;
	for (int m = 1; cin >> n && n; ++m) {
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", m, -_main(n));
	}
	return 0;
}
