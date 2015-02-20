/*
ID: 1010
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <queue>
#include <string.h>
#include <iomanip>
#include <limits.h>
using namespace std;

typedef long long _int;
#define MAX 101
int const MOD = INT_MAX;

_int ncr[MAX][MAX];

void generate() {
	for (int i = 0; i < MAX; ++i)
		ncr[i][0] = ncr[i][i] = 1;
	for (int i = 1; i < MAX; ++i)
		for (int j = 1; j < i; ++j)
			ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % (_int)MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	generate();
	for (int n, k; scanf("%d%d", &n, &k) != EOF && (n && k);) {
		printf("%d things taken %d at a time is %lld exactly.\n", n, k, ncr[n][k]);
	}
	return 0;
}