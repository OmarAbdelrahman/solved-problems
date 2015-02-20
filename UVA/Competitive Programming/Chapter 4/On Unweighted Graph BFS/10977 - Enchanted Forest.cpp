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

int const MAX = 205;

struct state {
	int x, y, c;
	state() {}
	state(int _x, int _y, int _c)
		: x(_x), y(_y), c(_c) {}
};

int n, m;
bool visited[MAX][MAX];
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };

double dist(int x1, int y1, int x2, int y2) {
	return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}

int solve(int xg, int yg) {
	queue<state> q;
	visited[xg][yg] = true;
	for (q.push(state(xg, yg, 0)); !q.empty(); q.pop()) {
		int x = q.front().x;
		int y = q.front().y;
		int c = q.front().c;
		if (x == n && y == m)
			return c;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m)
				if (!visited[nx][ny]) {
					q.push(state(nx, ny, c + 1));
					visited[nx][ny] = true;
				}
		}
	}
	return -1;
}

int main(int argc, char **args) {
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0)
			break;
		memset(visited, false, sizeof(visited));
		int q; scanf("%d", &q);
		while (q-- != 0) {
			int a, b; scanf("%d%d", &a, &b);
			visited[a][b] = true;
		}
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			int x1 = max(a - c, 1);
			int x2 = min(a + c, n);
			int y1 = max(b - c, 1);
			int y2 = min(b + c, m);
			for (int i = x1; i <= x2; ++i)
				for (int j = y1; j <= y2; ++j)
					if (dist(i, j, a, b) <= c * c)
						visited[i][j] = true;
		}
		int result = solve(1, 1);
		if (result == -1) printf("Impossible.\n"); else printf("%d\n", result);
	}
	return 0;
}