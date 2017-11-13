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

int const MAXN = 255;
int const BIG_NUM = 0x3f3f3f3f;

struct io_utilis {
	template<class T> static T next() {
		T n; std::cin >> n;
		return n;
	}
};

struct edge {
	int index, cost;
	edge() {}
	edge(int i, int c)
		: index(i), cost(c) {}
	bool operator < (const edge& e) const {
		return cost > e.cost;
	}
};

int C[MAXN][MAXN];
int T[MAXN];

static void initialize_all() {
	memset(C, -1, sizeof C);
	memset(T, 0, sizeof T);
}

static vector<int> solve(int src, int n, int s) {
	vector<int> distance(n, BIG_NUM);
	vector<bool> visited(n, false);
	priority_queue<edge> q;
	for (q.push(edge(src, 0)), distance[src] = 0; !q.empty();) {
		edge e = q.top(); q.pop();
		if (visited[e.index])
			continue;
		visited[e.index] = true;
		if (e.index < s) continue;
		for (int i = 0; i < n; ++i)
			if (C[e.index][i] >= 0) {
				if (e.cost + C[e.index][i] < distance[i]) {
					distance[i] = e.cost + C[e.index][i];
					q.push(edge(i, distance[i]));
				}
			}
	}
	return distance;
}

int main(int argc, char **args) {
	while (true) {
		int n = io_utilis::next<int>();
		int e = io_utilis::next<int>();
		int s = io_utilis::next<int>();
		int m = io_utilis::next<int>();
		if (n + e + s + m == 0)
			break;
		initialize_all();
		for (int i = 0; i < e; ++i) {
			int a = io_utilis::next<int>();
			int b = io_utilis::next<int>();
			int c = io_utilis::next<int>();
			C[a][b] = C[b][a] = c;
		}
		for (int i = s - 2; i >= 0; --i)
			T[i] = T[i + 1] + C[i][i + 1];
		vector<int> min_dist = solve(m, n, s);
		int result = BIG_NUM;
		for (int i = 0; i < s; ++i)
			result = min(result, min_dist[i] + T[i]);
		printf("%d\n", result);
	}
	return 0;
}