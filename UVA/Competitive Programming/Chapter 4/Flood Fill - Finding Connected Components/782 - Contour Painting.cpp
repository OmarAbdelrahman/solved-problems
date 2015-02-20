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

int const MAX = 100;
int const dx[] = { -1, 1, 0, 0 };
int const dy[] = { 0, 0, -1, 1 };

char border_ch;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

bool ok(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y <= m;
}

void solve(int x, int y) {
	if (visited[x][y])
		return;
	visited[x][y] = true;
	bool has_border = false;
	for (int i = 0; i < 4; ++i)
		if (ok(x + dx[i], y + dy[i]))
			if (grid[x + dx[i]][y + dy[i]] == border_ch) {
				has_border = true;
				break;
			}
	if (has_border) grid[x][y] = '#'; else grid[x][y] = ' ';
	for (int i = 0; i < 4; ++i)
		if (ok(x + dx[i], y + dy[i]))
			solve(x + dx[i], y + dy[i]);
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	cin.ignore();
	while (TC-- != 0) {
		n = m = 0;
		memset(visited, false, sizeof(visited));
		memset(grid, false, sizeof(grid));
		while (gets(grid[n]) && grid[n][0] != '_') {
			m = max(m, (int) strlen(grid[n]));
			for (int i = 0; i < strlen(grid[n]); ++i)
				if (grid[n][i] != ' ' && grid[n][i] != '*' && grid[n][i] != '_' && grid[n][i] != '#') {
					border_ch = grid[n][i];
					break;
				}
			n++;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; grid[i][j]; ++j)
				if (grid[i][j] == border_ch)
					visited[i][j] = true;
		for (int i = 0; i < n; ++i) {
			bool ok = false;
			for (int j = 0; grid[i][j]; ++j)
				if (grid[i][j] == '*') {
					ok = true;
					solve(i, j);
					break;
				}
			if (ok) break;
		}
		for (int i = 0; i < n; ++i)
			for (int j = strlen(grid[i]) - 1; j >= 0; --j)
				if (grid[i][j] == ' ') grid[i][j] = NULL; else break;
		for (int i = 0; i <= n; ++i)
			printf("%s\n", grid[i]);
	}
	return 0;
}