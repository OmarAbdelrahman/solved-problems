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

int const MAX = 1000 + 5;
char const PLAYER = 'J';
char const FIRE = 'F';
char const WALL = '#';
int const BIG_NUM = 0x3f3f3f3f;

struct state {
	int x, y;
	state() {}
	state(int _x, int _y)
		: x(_x), y(_y) {}
};

int n, m;
char grid[MAX][MAX];
int fire[MAX][MAX];
int dist[MAX][MAX];

void empty_queue(queue<state> &fringe) {
	for (; !fringe.empty(); fringe.pop());
}

void fill_costs(queue<state> &fringe, int A[][MAX]) {
	for (; !fringe.empty(); fringe.pop()) {
		int x = fringe.front().x;
		int y = fringe.front().y;
		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy)
				if ((dx == 0) ^ (dy == 0)) {
					int nx = dx + x;
					int ny = dy + y;
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						if (A[nx][ny] == BIG_NUM && grid[nx][ny] != WALL) {
							A[nx][ny] = A[x][y] + 1;
							fringe.push(state(nx, ny));
						}
					}
				}
	}
	empty_queue(fringe);
}

int solve() {
	int result = 0x3f3f3f3f;
	for (int i = 0; i < m; ++i) {
		if (grid[0][i] != WALL) {
			if (dist[0][i] < fire[0][i])
				result = min(result, dist[0][i]);
		}
		if (grid[n - 1][i] != WALL) {
			if (dist[n - 1][i] < fire[n - 1][i])
				result = min(result, dist[n - 1][i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (grid[i][0] != WALL) {
			if (dist[i][0] < fire[i][0])
				result = min(result, dist[i][0]);
		}
		if (grid[i][m - 1] != WALL) {
			if (dist[i][m - 1] < fire[i][m - 1])
				result = min(result, dist[i][m - 1]);
		}
	}
	return result;
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- != 0) {
		scanf("%d%d", &n, &m);
		queue<state> fringe;
		for (int i = 0; i < n; ++i) {
			scanf("%s", grid[i]);
			for (int j = 0; j < m; ++j) {
				fire[i][j] = BIG_NUM;
				dist[i][j] = BIG_NUM;
				if (grid[i][j] == FIRE) {
					fringe.push(state(i, j));
					fire[i][j] = 0;
				}
			}
		}
		fill_costs(fringe, fire);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (grid[i][j] == PLAYER) {
					dist[i][j] = 0;
					fringe.push(state(i, j));
				}
		fill_costs(fringe, dist);
		int result = solve();
		if (result >= 0x3f3f3f3f) printf("IMPOSSIBLE\n"); else printf("%d\n", result + 1);
	}
	return 0;
}