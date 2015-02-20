#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int const MAX = 50;
int d[MAX], v[MAX], n, w, nw[MAX];
int const WATER = 1100;
int dp[WATER][WATER], counter, ok = 0;
pair <int, int> items[MAX];

int solve(int index, int time) {
	int& res = dp[index][time];
	if (index == n) {
		return 0;
	}
	if (res != -1) {
		return res;
	}
	res = solve(index + 1, time);
	if (time - nw[index] >= 0) {
		res = max(res, v[index] + solve(index + 1, time - nw[index]));
	}
	return res;
}

void print(int x, int y) {
	if (x >= n) {
		return;
	}
	if (dp[x][y] != dp[x + 1][y]) {
		items[counter++] = make_pair(d[x], v[x]);
		print(x + 1, y - nw[x]);
	} else {
		print(x + 1, y);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	while (scanf("%d%d", &t, &w) != EOF) {
		counter = 0, scanf("%d", &n);
		if (ok++) puts("");
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &d[i], &v[i]);
			nw[i] = (w * d[i]) + (2 * w * d[i]);
		}
		memset(dp, -1, sizeof(dp));
		int m = solve(0, t);
		print(0, t);
		printf("%d\n%d\n", m, counter);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < counter; ++j)
				if (items[j].first == d[i] && items[j].second == v[i])
					printf("%d %d\n", d[i], v[i]);
		}
	}
	return 0;
}
