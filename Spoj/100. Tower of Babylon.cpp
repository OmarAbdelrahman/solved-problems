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

int const MAXN = 33 * 6;

struct cube {
	cube() {}
	cube(int _x, int _y, int _z)
		: x(_x), y(_y), z(_z) {}
	bool operator < (const cube& c) const {
		if (x != c.x)
			return x > c.x;
		if (y != c.y)
			return y > c.y;
		return z > c.z;
	}
	int x, y, z;
};

int n, dp[MAXN];
cube cubes[MAXN];

static inline void push(int& index, cube c) {
	cubes[index++] = c;
}

static inline bool can_put(cube a, cube b) {
	return (a.x > b.x && a.y > b.y) || (a.x > b.y && a.y > b.x);
}

int main(int argc, char **args) {
	int a, b, c;
	while (scanf("%d", &n) && n > 0) {
		int size = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			push(size, cube(a, b, c));
			push(size, cube(a, c, b));
			push(size, cube(b, a, c));
			push(size, cube(b, c, a));
			push(size, cube(c, a, b));
			push(size, cube(c, b, a));
		}
		sort(cubes, cubes + size);
		memset(dp, 0, sizeof(dp));
		int result = 0;
		for (int i = 0; i < size; ++i) {
			dp[i] = cubes[i].z;
			for (int j = 0; j < i; ++j)
				if (can_put(cubes[j], cubes[i]) && dp[i] < dp[j] + cubes[i].z)
					dp[i] = dp[j] + cubes[i].z;
			result = max(result, dp[i]);
		}
		printf("%d\n", result);
	}
	return 0;
}