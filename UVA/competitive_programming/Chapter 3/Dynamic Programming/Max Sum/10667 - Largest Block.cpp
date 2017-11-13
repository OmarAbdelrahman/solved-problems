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
#define MAX 105

int const INF = 100000;

int main() {
	int TC; scanf("%d", &TC);
	int grid[MAX][MAX];
	while (TC--) {
		int n; scanf("%d", &n);
		REP(i, n) REP(j, n) grid[i][j] = 1;
		int b; scanf("%d", &b);
		REP(i, b) {
			int r1, c1, r2, c2;
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			for (int i = r1 - 1; i < r2; ++i)
				for (int j = c1 - 1; j < c2; ++j)
					grid[i][j] = -INF;
		}
		REP(i, n) REP(j, n) if (j > 0) grid[i][j] += grid[i][j - 1];
		int res = -INF;
		bool uncounted = true;
		REP(left, n) for (int right = left; right < n; ++right) {
			int nmax = 0;
			REP(row, n) {
				if (left > 0)
					nmax += grid[row][right] - grid[row][left - 1];
				else
					nmax += grid[row][right];
				if (nmax < 0) nmax = 0;
				if (uncounted || nmax > res) {
					res = nmax;
					uncounted = false;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}