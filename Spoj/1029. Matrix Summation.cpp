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
using namespace std;

int const MAXN = 1030;
#define LSOne(s) (s & (-s))

struct fenwick {
	fenwick(int n) {
		a = vector<int>(n + 2, 0);
	}

	fenwick(int n, int m) {
		g = vector<vector<int> >(n + 2, vector<int>(m + 2, 0));
	}

	int read_a(int b) {
		int sum = 0;
		for (; b > 0; b -= LSOne(b))
			sum += a[b];
		return sum;
	}

	int read_a(int a, int b) {
		return read_a(b) - (a == 1 ? 0 : read_a(a - 1));
	}

	void update_a(int k, int v) {
		for (; k < a.size(); k += LSOne(k))
			a[k] += v;
	}

	int read_g(int x, int y) {
		if (x <= 0 || y <= 0)
			return 0;
		int res = 0;
		while (x > 0) {
			for (int y1 = y; y1 > 0; y1 -= LSOne(y1))
				res += g[x][y1];
			x -= LSOne(x);
		}
		return res;
	}

	void update_g(int x, int y, int v) {
		while (x < g.size()) {
			for (int y1 = y; y1 < g[0].size(); y1 += LSOne(y1))
				g[x][y1] += v;
			x += LSOne(x);
		}
	}

	vector<vector<int> > g;
	vector<int> a;
};

int grid[MAXN][MAXN];

int main(int argc, char **args) {
	int TC, x, y, x1, y1, v; scanf("%d", &TC);
	char cmd[4];
	while (TC-- > 0) {
		int n; scanf("%d", &n);
		fenwick tree(n, n);
		memset(grid, 0, sizeof grid);
		while (true) {
			scanf("%s", cmd);
			if (cmd[0] == 'E')
				break;
			if (cmd[1] == 'E') {
				scanf("%d%d%d", &x, &y, &v);
				tree.update_g(x + 1, y + 1, v - grid[x][y]);
				grid[x][y] = v;
			} else {
				scanf("%d%d%d%d", &x, &y, &x1, &y1);
				++x, ++y, ++x1, ++y1;
				printf("%d\n", tree.read_g(x1, y1) - tree.read_g(x1, y - 1) - tree.read_g(x - 1, y1) + tree.read_g(x - 1, y - 1));
			}
		}
	}
	return 0;
}