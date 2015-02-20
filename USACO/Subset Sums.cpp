/*
ID: 1010
PROG: subset
LANG: C++
*/

#include "iostream"
#include "cstdio"
#include "map"
#include "string"
#include "queue"
#include "cmath"
#include "numeric"
#include "string.h"
using namespace std;

#define sz(a) ((int)a.size())

int n;
int sum;
int *numbers;
int answer;
vector<vector<int> > dp;

int solve(int x, int acc) {
	if (x == n) return 0;
	if (dp[x][acc] != -1) return dp[x][acc];
	if (acc == sum - acc) return answer + 1;
	return dp[x][acc] = solve(x + 1, acc + numbers[x]) + solve(x + 1, acc);
}

int main() {
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	scanf("%d", &n);
	numbers = new int[n];
	sum = 0, answer = 0;
	int i;
	for (i = 0; i < n; ++i)
		sum += i + 1, numbers[i] = i + 1;
	if (sum & 1) {
		puts("0");
		return 0;
	}
	dp = vector<vector<int> >(n + 1, vector<int>(sum + 1, -1));
	printf("%d\n", solve(0, 0));
	delete numbers;
	return 0;
}