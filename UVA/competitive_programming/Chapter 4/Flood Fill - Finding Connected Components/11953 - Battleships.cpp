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

typedef long long int64;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100 + 5;

string grid[MAX];

void fill(int x, int y, int size, bool &ok) {
	if (grid[x][y] == '.')
		return;
	if (grid[x][y] == 'x') ok = true;
	grid[x][y] = '.';
	for (int dx = -1; dx <= 1; ++dx)
		for (int dy = -1; dy <= 1; ++dy)
			if ((dx == 0) ^ (dy == 0)) {
				int nx = x + dx;
				int ny = y + dy;
				if (nx >= 0 && nx < size && ny >= 0 && ny < size)
					if (grid[nx][ny] == 'x' || grid[nx][ny] == '@')
						fill(nx, ny, size, ok);
			}
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	for (int c = 1, n; cin >> n && T-- != 0; ++c) {
		for (int i = 0; i < n; ++i)
			cin >> grid[i];
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				bool ok = false;
				if (grid[i][j] == 'x' || grid[i][j] == '@')
					fill(i, j, n, ok);
				res += (int) ok;
			}
		printf("Case %d: %d\n", c, res);
	}
	return 0;
}
