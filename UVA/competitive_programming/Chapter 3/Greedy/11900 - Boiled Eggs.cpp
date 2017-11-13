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
#define SZ(a) ((int)a.size())
#define FOR(i, s, e) for (int i = s; i < e; ++i)
#define REP(i, e) for (int i = 0; i < e; ++i)
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(c) c.begin(), c.end()
#define MAX 30005

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cases; scanf("%d", &cases);
	for (int c = 1; cases--; c++)
	{
		int n, p, q; scanf("%d%d%d", &n, &p, &q);
		vector<int> w(n);
		REP(i, n) scanf("%d", &w[i]);
		int sw = 0, taken = 0;
		REP(i, n) if (sw + w[i] <= q && taken < p) sw += w[i], taken++; else break;
		printf("Case %d: %d\n", c, taken);
	}
	return 0;
}