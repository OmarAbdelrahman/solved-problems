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

typedef long long ll;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100;

class Graph {
public:
	vector<int> color;
	vector<vector<pair<int, int> > > L;
	vector<bool> visited;

	Graph(int n) { init(n); }

	void init(int n) {
		color = vector<int>(n, 2);
		L = vector<vector<pair<int, int> > >(n);
		visited = vector<bool>(n, false);
	}

	void add(int a, int b, int c = 0) {
		L[a].push_back(pii(b, c));
		L[b].push_back(pii(a, c));
	}

	int bipartiteCost(int s = 0) {
		queue<int> q;
		int boys = 0;
		int girls = 0;
		color[s] = 1;
		visited[s] = true;
		bool bipartite = true;
		for (q.push(s); !q.empty(); q.pop()) {
			int index = q.front();
			boys += color[index] == 1;
			girls += color[index] == 0;
			for (int i = 0; i < SIZE(L[index]); ++i) {
				int next = L[index][i].first;
				if (!visited[next]) {
					visited[next] = true;
					color[next] = 1 - color[index];
					q.push(next);
				} else if (color[next] == color[index])
					bipartite = false;
			}
		}
		return bipartite ? max(boys, girls) : -1;
	}
};

int solve(Graph g) {
	int res = 0;
	for (int i = 0; i < SIZE(g.L); ++i)
		if (g.color[i] == 2) {
			int now = g.bipartiteCost(i);
			if (now == -1) continue;
			res += now;
		}
	return res;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	while (T-- != 0) {
		int nodes; cin >> nodes;
		Graph graph(nodes);
		for (int i = 0; i < nodes; ++i) {
			int edges; cin >> edges;
			if (edges == 0) continue;
			for (int j = 0; j < edges; ++j) {
				int k; cin >> k;
				if (k - 1 < nodes)
					graph.add(i, k - 1);
			}
		}
		cout << solve(graph) << endl;
	}
	return 0;
}
