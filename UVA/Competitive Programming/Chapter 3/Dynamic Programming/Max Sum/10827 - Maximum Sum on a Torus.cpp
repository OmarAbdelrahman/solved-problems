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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

#define two(n) (1 << (n))
#define on(m, n) (((m) & two(n)) != 0)
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define REP(i, n) for (int i = 0; i < n; i++)
#define MAX 80 * 2

int const oo = 1 << 30;

inline void get_max(int &a, int b) {
	if (a < b) a = b;
}

int main() {
	int TC; scanf("%d", &TC);
	int grid[MAX][MAX];
	while (TC-- != 0) {
		int n; scanf("%d", &n);
		REP(i, n) REP(j, n) {
			scanf("%d", &grid[i][j]);
			grid[i][j + n] = grid[i + n][j] = grid[i + n][j + n] = grid[i][j];
		}
		int m = n * 2;
		REP(i, m) REP(j, m) if (i > 0) grid[i][j] += grid[i - 1][j];
		int res = -oo;
		for (int up = 1; up <= n; ++up)
			REP(down, m - up) REP(left, n) {
				int sum = 0;
				for (int right = left; right < n + left; ++right) {
					if (sum < 0) sum = 0;
					sum += grid[up + down][right] - grid[down][right];
					get_max(res, sum);
				}
			}
		printf("%d\n", res);
	}
	return 0;
}