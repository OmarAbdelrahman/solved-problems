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

struct Graph {
	vector<vector<int> > L;
	vector<vector<int> > T;
	vector<int> topSort;
	vector<int> component;
	vector<bool> visited;
	int compCnt;

	Graph(int n) { init(n); }

	void init(int n) {
		L = vector<vector<int> >(n);
		T = vector<vector<int> >(n);
		topSort.clear();
		component = vector<int>(n, 0);
		visited = vector<bool>(n, false);
		compCnt = 0;
	}

	void add(int a, int b) {
		L[a].push_back(b);
		T[b].push_back(a);
	}

	void doTopSort() {
		for (int i = 0; i < SIZE(L); i++)
			if (!visited[i])
				dfs(i);
		reverse(topSort.begin(), topSort.end());
	}

	void dfs(int u) {
		visited[u] = true;
		for (int i = 0; i < SIZE(L[u]); i++)
			if (!visited[L[u][i]])
				dfs(L[u][i]);
		topSort.push_back(u);
	}

	void doKosaraju() {
		for (int i = 0; i < SIZE(topSort); i++)
			if (visited[topSort[i]])
				kosaraju(topSort[i], compCnt++);
	}

	void kosaraju(int u, int compID) {
		visited[u] = false;
		component[u] = compID;
		for (int i = 0; i < SIZE(T[u]); i++)
			if (visited[T[u][i]])
				kosaraju(T[u][i], compID);
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	for (int n, e, c = 1; cin >> n >> e && T-- != 0; ++c) {
		Graph graph(n);
		for (int i = 0; i < e; i++) {
			int a, b; cin >> a >> b;
			graph.add(a - 1, b - 1);
		}
		graph.doTopSort();
		graph.doKosaraju();
		vector<int> indegree(graph.compCnt);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < SIZE(graph.L[i]); j++)
				if (graph.component[i] != graph.component[graph.L[i][j]])
					++indegree[graph.component[graph.L[i][j]]];
		int res = 0;
		for (int i = 0; i < SIZE(indegree); i++)
			res += indegree[i] == 0;
		printf("Case %d: %d\n", c, res);
	}
	return 0;
}
