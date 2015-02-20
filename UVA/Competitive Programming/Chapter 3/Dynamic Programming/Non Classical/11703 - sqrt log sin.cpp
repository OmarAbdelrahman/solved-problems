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

int const MOD = 1000000;

int dp[MOD + 1];

int main() {
	freopen("in.txt", "r", stdin);
	dp[0] = 1;
	for (int i = 1; i <= MOD; ++i) {
		dp[i] = dp[(int)floor(i - sqrt(i * 1.0))] + dp[(int)floor(log(i * 1.0))] + dp[(int)floor(i * sin(i * 1.0) * sin(i * 1.0))];
		dp[i] %= MOD;
	}
	for (int n; scanf("%d", &n) && n != -1; printf("%d\n", dp[n]));
	return 0;
}