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
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 20 + 5;

int h, w;
string grid[MAX];
bool visited[MAX][MAX];
int kx, ky;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int flood(int x, int y, char land) {
	if (visited[x][y])
		return 0;
	visited[x][y] = true;
	int cnt = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = (y + dy[i] + w) % w;
		if (nx >= 0 && nx < h && grid[nx][ny] == land && !visited[nx][ny])
			cnt += flood(nx, ny, land);
	}
	return cnt;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while (cin >> h >> w) {
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < h; ++i)
			cin >> grid[i];
		cin >> kx >> ky;
		char land = grid[kx][ky];
		flood(kx, ky, land);
		int res = 0;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (grid[i][j] == land && !visited[i][j])
					res = max(res, flood(i, j, land));
		cout << res << endl;
	}
	return 0;
}
