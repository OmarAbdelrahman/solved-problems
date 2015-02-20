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

int const MAXN = 81;

int n, m;
int longest;
int cache[MAXN][MAXN];
char a[MAXN];
char b[MAXN];
set<string> answer;

static inline void get_max(int& a, int b) {
	if (a < b) a = b;
}

static int solve(int i, int j) {
	if (i >= n || j >= m)
		return 0;
	if (cache[i][j] > -1)
		return cache[i][j];
	if (a[i] == b[j])
		cache[i][j] = solve(i + 1, j + 1) + 1;
	get_max(cache[i][j], max(solve(i + 1, j), solve(i, j + 1)));
	return cache[i][j];
}

static void path(int i, int j, int length, string result) {
	if (length == 0) {
		answer.insert(result);
		return;
	}
	for (int x = i + 1; x < n; ++x)
		for (int y = j + 1; y < m; ++y)
			if (a[x] == b[y] && cache[x][y] == length)
				path(x, y, length - 1, result + a[x]);
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%s%s", a, b);
		n = strlen(a);
		m = strlen(b);
		memset(cache, -1, sizeof cache);
		longest = solve(0, 0);
		answer.clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i] == b[j] && cache[i][j] == longest)
					path(i, j, longest - 1, string("") + a[i]);
		vector<string> result(answer.begin(), answer.end());
		for (int i = 0; i < result.size(); ++i)
			printf("%s\n", result[i].c_str());
		if (TC > 0)
			printf("\n");
	}
	return 0;
}