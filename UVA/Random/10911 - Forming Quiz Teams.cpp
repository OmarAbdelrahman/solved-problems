#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int64;
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define FOR(i, s, e) for (int i = s; i < e; ++i)
#define REP(i, e) for (int i = 0; i < e; ++i)
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(c) c.begin(), c.end()

int N, sz;
double dp[1 << 16];
double dist[20][20];

double solve(int mask) {
	if (mask == (1 << sz) - 1) return 0.; // all taken
	double& ret = dp[mask];
	if (ret > -0.5) return ret;
	double res = (double)LLONG_MAX;
	for (int i = 0; i < sz; ++i)
		if (!(mask & (1 << i)))
			for (int j = i + 1; j < sz; ++j)
				if (!(mask & (1 << j))) {
					res = min(res, dist[i][j] + solve(mask | (1 << i) | (1 << j)));
				}
	return ret = res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	string temp;
	int x[20], y[20];
	for (int c = 1; cin >> N && N; ++c) {
		sz = 2 * N;
		for (int i = 0; i < sz; ++i)
			cin >> temp >> x[i] >> y[i];
		for (int i = 0; i < sz; ++i)
			for (int j = 0; j < sz; ++j)
				dist[i][j] = hypot((double)x[i] - x[j], (double)y[i] - y[j]);
		memset(dp, -1, sizeof(dp));
		printf("Case %d: %.2lf\n", c, solve(0));
	}
	return 0;
}
