#include <iostream>
#include <cstdio>
#include <string.h>
#include <limits.h>
using namespace std;

typedef long long int64;
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
int const MAX = 10 + 5;

int n;
int64 rows[MAX];
int64 cols[MAX];
int64 memo[MAX][MAX];
int best[MAX][MAX];

int64 f(int left, int right) {
	if (left >= right) return 0;
	if (right - left == 1)
		return rows[left] * cols[left] * cols[right];
	if (memo[left][right] != -1)
		return memo[left][right];
	memo[left][right] = LLONG_MAX / 2;
	for (int mid = left; mid <= right; ++mid) {
		int64 value = f(left, mid) + f(mid + 1, right) + (rows[left] * cols[mid] * cols[right]);
		if (value < memo[left][right]) {
			memo[left][right] = value;
			best[left][right] = mid;
		}
	}
	return memo[left][right];
}

void printPath(int left, int right) {
	if (left == right)
		cout << "A" << left + 1;
	else {
		cout << "(";
		if (best[left][right] != -1) {
			printPath(left, best[left][right]);
			cout << " x ";
			printPath(best[left][right] + 1, right);
		} else {
			printf("A%d x A%d", left + 1, right + 1);
		}
		cout << ")";
	}
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int c = 1; cin >> n && n; ++c) {
		for (int i = 0; i < n; ++i)
			cin >> rows[i] >> cols[i];
		memset(memo, -1, sizeof(memo));
		memset(best, -1, sizeof(best));
		f(0, n - 1);
		printf("Case %d: ", c);
		printPath(0, n - 1);
		puts("");
	}
	return 0;
}
