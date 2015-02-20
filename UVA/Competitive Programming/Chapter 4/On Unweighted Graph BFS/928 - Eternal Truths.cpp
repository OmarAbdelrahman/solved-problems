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

int const MAX = 305;
char const WALL = '#';

struct state {
	int x, y, s, c;
	state() {}
	state(int _x, int _y, int _s, int _c)
		: x(_x), y(_y), s(_s), c(_c) {}
};

int n, m;
char grid[MAX][MAX];

bool can_go(int x, int y, int dx, int dy, int s) {
	for (int i = 0; i < s; ++i) {
		x += dx;
		y += dy;
		if (grid[x][y] == WALL)
			return false;
	}
	return true;
}

int solve(int xg, int yg) {
	bool visited[MAX][MAX][4];
	memset(visited, false, sizeof(visited));
	queue<state> q;
	visited[xg][yg][0] = true;
	for (q.push(state(xg, yg, 0, 0)); !q.empty(); q.pop()) {
		int x = q.front().x;
		int y = q.front().y;
		int s = q.front().s;
		int c = q.front().c;
		if (grid[x][y] == WALL)
			continue;
		if (grid[x][y] == 'E')
			return c;
		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy)
				if ((dx == 0) ^ (dy == 0)) {
					int nx = (s + 1) * dx + x;
					int ny = (s + 1) * dy + y;
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != WALL)
						if (!visited[nx][ny][s + 1]) {
							if (can_go(x, y, dx, dy, s)) {
								q.push(state(nx, ny, (s + 1) % 3, c + 1));
								visited[nx][ny][s + 1] = true;
							}
						}
				}
	}
	return -1;
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- != 0) {
		scanf("%d%d", &n, &m);
		int x = -1;
		int y = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%s", grid[i]);
			for (int j = 0; j < m; ++j)
				if (grid[i][j] == 'S') {
					x = i;
					y = j;
				}
		}
		int result = solve(x, y);
		if (result == -1) printf("NO\n"); else printf("%d\n", result);
	}
	return 0;
}