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

typedef long long lli;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100;
int const INF = 1000000;

class Graph {
public:
	vector<vector<int> > L;
	vector<vector<int> > T;
	vector<bool> visited;
	vector<int> component;
	vector<int> topSort;
	int numCnt;
	int numScc;

	Graph(int n) { init(n); }

	void init(int n) {
		L = vector<vector<int> >(n);
		T = vector<vector<int> >(n);
		visited = vector<bool>(n, false);
		component = vector<int>(n, -1);
		numCnt = numScc = 0;
	}

	void add(int a, int b) {
		L[a].push_back(b);
		T[b].push_back(a);
	}

	void doTopSort() {
		for (int i = 0; i < SIZE(L); ++i)
			if (!visited[i])
				dfs(i);
		reverse(topSort.begin(), topSort.end());
	}

	void dfs(int u) {
		visited[u] = true;
		for (int i = 0; i < SIZE(L[u]); ++i) {
			int next = L[u][i];
			if (!visited[next])
				dfs(next);
		}
		topSort.push_back(u);
	}

	void doKosaraju() {
		for (int i = 0; i < SIZE(topSort); ++i)
			if (visited[topSort[i]])
				getComponents(topSort[i], numScc++);
	}

	void getComponents(int u, int c) {
		visited[u] = false;
		component[u] = c;
		for (int i = 0; i < SIZE(T[u]); ++i) {
			int next = T[u][i];
			if (visited[next])
				getComponents(next, c);
		}
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	for (int nodes, edges; cin >> nodes >> edges && T-- != 0;) {
		Graph graph(nodes);
		for (int i = 0; i < edges; ++i) {
			int a, b; cin >> a >> b;
			graph.add(a - 1, b - 1);
		}
		graph.doTopSort();
		graph.doKosaraju();
		vector<int> indegree(graph.numScc);
		for (int i = 0; i < nodes; ++i)
			for (int j = 0; j < SIZE(graph.L[i]); ++j)
				if (graph.component[i] != graph.component[graph.L[i][j]])
					++indegree[graph.component[graph.L[i][j]]];
		int res = 0;
		for (int i = 0; i < graph.numScc; ++i)
			if (indegree[i] == 0)
				++res;
		cout << res << endl;
	}
	return 0;
}
