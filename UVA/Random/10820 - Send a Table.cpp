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
#include <fstream>
using namespace std;

const int MAXN = 50010;

int dp[MAXN];
int phi[MAXN];

static inline void fillPhi() {
	memset(phi, 0, sizeof phi);
	phi[1] = 1;
	for (int i = 2; i < MAXN; ++i)
		if (phi[i] == 0) { 
			for (int j = i; j < MAXN; j += i) {
				if (phi[j] == 0) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
}

int main(int argc, char **args) {
	fillPhi();

	dp[1] = 1;
	for (int i = 2; i < MAXN; ++i)
		dp[i] = dp[i - 1] + phi[i] * 2;

	for (int n; cin >> n && n; cout << dp[n] << endl);
	return 0;
}