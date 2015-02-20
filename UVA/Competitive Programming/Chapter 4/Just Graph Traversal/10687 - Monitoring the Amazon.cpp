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

int const MAXN = 1000 + 5;

struct edge {
	int x, y, node, dist;
	edge() {}
	edge(int _x, int _y, int _node, int _dist)
		: x(_x), y(_y), node(_node), dist(_dist) {}
	bool operator < (const edge &e) const {
		if (e.dist != dist)
			return dist < e.dist;
		if (e.x != x)
			return x < e.x;
		return y < e.y;
	}
};

inline int square(int x) {
	return x * x;
}

int x[MAXN];
int y[MAXN];
vector<edge> edges[MAXN];
bool visited[MAXN];

void dfs(int index) {
	if (visited[index])
		return;
	visited[index] = true;
	for (int i = 0; i < 2 && i < edges[i].size(); ++i)
		dfs(edges[index][i].node);
}

int main(int argc, char **args) {
	for (int n; scanf("%d", &n) && n != 0;) {
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x[i], &y[i]);
			edges[i].clear();
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i != j)
					edges[i].push_back(edge(x[j], y[j], j, square(x[i] - x[j]) + square(y[i] - y[j])));
		for (int i = 0; i < n; ++i)
			sort(edges[i].begin(), edges[i].end());
		dfs(0);
		if (count(visited, visited + n, true) == n)
			puts("All stations are reachable.");
		else
			puts("There are stations that are unreachable.");
	}
	return 0;
}