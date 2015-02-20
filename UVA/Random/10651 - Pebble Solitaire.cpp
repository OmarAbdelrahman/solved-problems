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
#define MAX 12

int dp[1 << 13];

int solve(int mask) {
	if (mask <= 0) return 0;
	if (dp[mask] != -1) return dp[mask];
	dp[mask] = INT_MAX;
	bool cant = true;
	for (int a = 0; a < MAX; ++a) {
		if (a + 2 < MAX) {
			if ((mask & (1 << a)) && (mask & (1 << (a + 1))) && !(mask & (1 << (a + 2)))) {
				cant = false;
				int mask1 = mask;
				mask1 |= (1 << (a + 2));
				mask1 &= ~(1 << (a + 1));
				mask1 &= ~(1 << a);
				dp[mask] = min(dp[mask], solve(mask1));
			}
		}
		if (a - 1 >= 0) {
			if ((mask & (1 << a)) && (mask & (1 << (a + 1))) && !(mask & (1 << (a - 1)))) {
				cant = false;
				int mask1 = mask;
				mask1 |= (1 << (a - 1));
				mask1 &= ~(1 << (a + 1));
				mask1 &= ~(1 << a);
				dp[mask] = min(dp[mask], solve(mask1));
			}
		}
	}
	int cnt = 0;
	if (cant) {
		for (int a = 0; a < MAX; ++a)
			if (mask & (1 << a)) ++cnt;
		return dp[mask] = min(dp[mask], cnt);
	}
	return dp[mask];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cases; cin >> cases;
	while (cases--) {
		string str; cin >> str;
		int mask = 0;
		for (int a = 0; a < str.length(); ++a)
			if (str[a] == 'o') mask |= (1 << a);
		memset(dp, -1, sizeof(dp));
		cout << solve(mask) << endl;
	}
	return 0;
}