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
	vector<int> num, low;
	vector<bool> visited;
	vector<int> component;
	int numScc, numCnt;

	Graph(int n) { init(n); }

	void init(int n) {
		L = vector<vector<int> >(n);
		num = vector<int>(n, -1);
		low = vector<int>(n, 0);
		visited = vector<bool>(n, false);
		component.clear();
		numScc = numCnt = 0;
	}

	void add(int a, int b, bool undirected) {
		L[a].push_back(b);
		if (undirected)
			L[b].push_back(a);
	}

	void doTarjan() {
		for (int i = 0; i < SIZE(L); ++i)
			if (num[i] == -1)
				tarjan(i);
	}

	void tarjan(int u) {
		low[u] = num[u] = numCnt++;
		visited[u] = true;
		component.push_back(u);
		for (int i = 0; i < SIZE(L[u]); ++i) {
			int v = L[u][i];
			if (num[v] == -1)
				tarjan(v);
			if (visited[v])
				low[u] = min(low[u], low[v]);
		}
		if (num[u] == low[u]) {
			numScc++;
			int v;
			do {
				v = component[SIZE(component) - 1];
				visited[v] = false;
				component.erase(--component.end());
			} while (v != u);
		}
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int nodes, edges; cin >> nodes >> edges;) {
		if (nodes == 0 && edges == 0)
			break;
		Graph graph(nodes);
		for (int i = 0; i < edges; ++i) {
			int a, b, c; cin >> a >> b >> c;
			graph.add(a - 1, b - 1, c == 2 ? true : false);
		}
		graph.doTarjan();
		graph.numScc == 1 ? puts("1") : puts("0");
	}
	return 0;
}
