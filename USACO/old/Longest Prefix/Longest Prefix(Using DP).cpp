/*
ID: 1010
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <string.h>
using namespace std;

#define sz(a) ((int)a.size())
#define max_t 200000 + 10

vector<string> prim;
string seq;
int dp[max_t];

template<class T> inline void get_max(T& a, T b) {
	if (a < b) a = b;
}

inline bool ok(int st, int i) {
	for (int j = 0; j < sz(prim[i]); ++j)
		if (prim[i][j] != seq[st + j]) return false;
	return true;
}

int solve(int len) {
	if (len == sz(seq)) return len;
	int& ans = dp[len], big = 0;
	if (ans != -1) return ans;
	bool flag = false;
	for (int i = 0; i < sz(prim); ++i)
		if (len + sz(prim[i]) <= sz(seq))
			if (ok(len, i)) {
				flag = true;
				get_max(big, solve(len + sz(prim[i])));
			}
	if (!flag) big = len;
	return ans = big;
}

int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	for (string s; cin >> s && s != "."; prim.push_back(s));
	for (string s; cin >> s; seq += s);
	fill(dp, dp + max_t, -1);
	cout << solve(0) << endl;
	return 0;
}