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
	vector<int> dist;
	vector<vector<pair<int, int> > > L;
	vector<bool> visited;

	Graph(int n) { init(n); }

	void init(int n) {
		dist = vector<int>(n, 2);
		L = vector<vector<pair<int, int> > >(n);
		visited = vector<bool>(n, false);
	}

	void addEdge(int a, int b, int c, bool undirected) {
		L[a].push_back(pii(b, c));
		if (undirected)
			L[b].push_back(pii(a, c));
	}

	int bipartiteCost(int s = 0) {
		queue<int> q;
		int boys = 0;
		int girls = 0;
		dist[s] = 1;
		visited[s] = true;
		for (q.push(s); !q.empty(); q.pop()) {
			int index = q.front();
			boys += dist[index] == 1;
			girls += dist[index] == 0;
			for (int i = 0; i < SIZE(L[index]); ++i) {
				int next = L[index][i].first;
				if (!visited[next]) {
					visited[next] = true;
					dist[next] = 1 - dist[index];
					q.push(next);
				} else if (dist[next] == dist[index])
					return -1;
			}
		}
		if (girls + boys == 1) return 1;
		return min(boys, girls);
	}
};

int solve(Graph graph) {
	int res = 0;
	for (int i = 0; i < SIZE(graph.L); ++i)
		if (graph.dist[i] == 2) {
			int now = graph.bipartiteCost(i);
			if (now == -1) return now;
			res += now;
		}
	return res;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	for (int vertex, edges; cin >> vertex >> edges && T-- != 0;) {
		Graph graph(vertex);
		for (int i = 0, a, b; i < edges; ++i) {
			cin >> a >> b;
			graph.addEdge(a, b, 0, true);
		}
		cout << solve(graph) << endl;
	}
	return 0;
}
