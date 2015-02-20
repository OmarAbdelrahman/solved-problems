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

#define M 110

int grid[M][M];
int dominates[M][M];
bool reachable[M];
int nodes;

void print_lines() {
	printf("+");
	for (int i = 1; i < 2 * ::nodes; ++i)
		printf("-");
	puts("+");
}

void print_result() {
	print_lines();
	for (int i = 0; i < ::nodes; ++i) {
		printf("|");
		for (int j = 0; j < ::nodes; ++j)
			printf((dominates[i][j] ? "Y|" : "N|"));
		puts("");
		print_lines();
	}
}

void dfs(int now_node, int now_grid[][M], bool vis[], int ignore) {
	if (now_node == ignore)
		return;
	vis[now_node] = true;
	for (int i = 0; i < ::nodes; ++i)
		if (!vis[i] && now_grid[now_node][i]) {
			dfs(i, now_grid, vis, ignore);
		}
}

int main() {
	int cases; scanf("%d", &cases);
	for (int c = 1; cases--; ++c) {
		scanf("%d", &nodes);
		memset(dominates, 0, sizeof(dominates));
		memset(reachable, false, sizeof(reachable));
		for (int i = 0; i < nodes; ++i)
			for (int j = 0; j < nodes; ++j) {
				int num; scanf("%d", &num);
				grid[i][j] = num;
			}
		dfs(0, grid, reachable, -1);
		bool visited[M];
		for (int cur_node = 0; cur_node < nodes; ++cur_node) {
			memset(visited, false, sizeof(visited));
			dfs(0, grid, visited, cur_node);
			for (int i = 0; i < nodes; ++i)
				if (!visited[i] && reachable[i]) {
					dominates[cur_node][i] = true;
				}
		}
		dominates[0][0] = reachable[0];
		printf("Case %d:\n", c);
		print_result();
	}
	return 0;
}