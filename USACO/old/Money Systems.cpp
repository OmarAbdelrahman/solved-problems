/*
ID: 1010
PROG: money
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;

#define max_t 10000 + 5
typedef long long Int;

int coins_number, value;
int coins[26];
Int dp[max_t];

void solve() {
	dp[0] = dp[1] = 1;
	for (int i = 0; i < coins_number; ++i)
		for (int j = 1; j + coins[i] < max_t; ++j)
			dp[j + coins[i]] += dp[j];
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	cin >> coins_number >> value;
	for (int i = 0; i < coins_number; ++i)
		cin >> coins[i];
	solve();
	cout << dp[++value] << endl;
	return 0;
}