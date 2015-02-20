/*
ID: 1010
PROG: nocows
LANG: C++
*/

#include <iostream>
#include <cstdio>
using namespace std;

#define MOD 9901

int n, k;
int dp[101][201];

int solve() {
	for (int i = 1; i <= k; ++i) dp[i][1] = 1;
	for (int height = 2; height <= k; ++height)
		for (int node = 3; node <= n; node += 2)
			for (int numNodes = 1; numNodes <= node - 2; numNodes += 2) {
				dp[height][node] += (dp[height - 1][numNodes] * dp[height - 1][node - numNodes - 1]);
				dp[height][node] %= MOD;
			}
	return (dp[k][n] - dp[k - 1][n] + MOD) % MOD;
}

int main() {
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	cin >> n >> k;
	printf("%d\n", n & 1 ? solve() : 0);
	return 0;
}