/*
ID: 1010
PROG: stamps
LANG: C++
*/

#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

typedef long long _int;
#define sz(a) ((int)a.size())
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define for_each(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define all(c) c.begin(), c.end()
#define M 200 * 10000 + 1

int K, N;
vector<int> vals;
int dp[M];

int solve(int res) {
	if (res == 0) return 0;
	if (dp[res] != -1) return dp[res];
	dp[res] = M + 5;
	for (int i = 0; i < vals.size(); ++i)
		if (res - vals[i] >= 0)
			dp[res] = min(solve(res - vals[i]) + 1, dp[res]);
	return dp[res];
}

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	cin >> K >> N;
	int big = -1;
	for (int i = 0; i < N; ++i) {
		int n; scanf("%d", &n);
		vals.push_back(n); big = max(big, n);
	}
	big *= K;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= big + 1; ++i)
		if (solve(i) > K) {
			printf("%d\n", i - 1);
			break;
		}
	return 0;
}