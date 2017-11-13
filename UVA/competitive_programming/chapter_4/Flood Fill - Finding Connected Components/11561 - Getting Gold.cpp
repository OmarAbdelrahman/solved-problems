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

char const GOLD = 'G';
char const PLAYER = 'P';
char const TRAP = 'T';
char const WALL = '#';
char const EMPTY = '.';
int const MAX = 55;

int n, m, result;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };

void solve(int x, int y) {
	if (grid[x][y] == WALL || visited[x][y])
		return;
	if (grid[x][y] == GOLD)
		++result;
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			if (grid[nx][ny] == TRAP)
				return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			solve(nx, ny);
	}
}

int main(int argc, char **args) {
	while (scanf("%d%d", &m, &n) != EOF) {
		int x = -1;
		int y = -1;
		result = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", grid[i]);
			for (int j = 0; j < m; ++j)
				if (grid[i][j] == PLAYER) {
					x = i;
					y = j;
				}
		}
		memset(visited, false, sizeof(visited));
		solve(x, y);
		printf("%d\n", result);
	}
	return 0;
}