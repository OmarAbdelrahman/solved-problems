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

int64 dp[MAX];
int64 coins[] = {1, 5, 10, 25, 50};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	dp[0] = dp[1] = 1;
	REP(i, 5) for (int val = 1; val + coins[i] < MAX; val++)
		dp[val + coins[i]] += dp[val];
	int n;
	while (scanf("%d", &n) != EOF)
		if (dp[n + 1] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %lld ways to produce %d cents change.\n", dp[n + 1], n);
	return 0;
}