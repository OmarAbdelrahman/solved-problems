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
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

int const MAX = 67;

long long dp[MAX][MAX][2];

int main(int argc, char **args) {
	int i, drawer, secure, lock;
	for (i = 0; i < 2; i++)
		dp[0][0][i] = 1;
	for (drawer = 0; drawer + 1 < MAX; drawer++)
		for (secure = 0; secure <= drawer; secure++)
			for (lock = 0; lock < 2; lock++) {
				dp[drawer + 1][secure][0] += dp[drawer][secure][lock];
				dp[drawer + 1][secure + lock][1] += dp[drawer][secure][lock];
			}
	while (scanf("%d%d", &drawer, &secure) && (drawer >= 0 && secure >= 0))
		printf("%lld\n", dp[drawer][secure][1]);
	return 0;
}