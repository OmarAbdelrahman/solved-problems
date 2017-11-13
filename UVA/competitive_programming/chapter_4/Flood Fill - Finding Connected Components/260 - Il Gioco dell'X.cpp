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

typedef long long lli;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
int const MAX = 100;
int const INF = 1000000;

int dx[] = {-1, 0, 1, -1, 0, 1};
int dy[] = {-1, -1, 0, 0, 1, 1};

bool check(int x, int y, vector<string> &grid)
{
	if (x == SIZE(grid) - 1)
		return true;
	grid[x][y] = '.';
	bool ok = false;
	for (int i = 0; i < 6; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < SIZE(grid) && ny >= 0 && ny < SIZE(grid) && grid[nx][ny] == 'b')
			ok |= check(nx, ny, grid);
	}
	return ok;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int n, c = 1; cin >> n && n; c++)
	{
		vector<string> grid(n);
		for (int i = 0; i < n; i++)
			cin >> grid[i];
		bool black = false;
		for (int i = 0; i < n && !black; i++)
			if (grid[0][i] == 'b')
				black |= check(0, i, grid);
		printf("%d %c\n", c, black ? 'B' : 'W');
	}
	return 0;
}
