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

map<string, int> val;
map<int, string> key;

class Graph {
public:
	vector<int> num;
	vector<int> low;
	vector<bool> visited;
	vector<vector<pair<int, int> > > L;
	vector<int> component;
	vector<vector<int> > scc;
	int numScc;
	int numCounter;

	Graph(int n) { init(n); }

	void init(int n) {
		numCounter = numScc = 0;
		num = vector<int>(n, -1);
		low = vector<int>(n, 0);
		L = vector<vector<pair<int, int> > >(n);
		visited = vector<bool>(n, false);
		component.clear();
		scc.clear();
	}

	void addEdge(int a, int b, int c = 0) {
		L[a].push_back(pii(b, c));
	}

	void doTarjan() {
		for (int i = 0; i < SIZE(L); ++i)
			if (num[i] == -1)
				tarjan(i);
	}

	void tarjan(int u) {
		low[u] = num[u] = numCounter++;
		component.push_back(u);
		visited[u] = true;
		for (int i = 0; i < SIZE(L[u]); ++i) {
			int v = L[u][i].first;
			if (num[v] == -1)
				tarjan(v);
			if (visited[v])
				low[u] = min(low[u], low[v]);
		}
		if (low[u] == num[u]) {
			numScc++;
			vector<int> now;
			while (true) {
				int v = component[SIZE(component) - 1];
				visited[v] = false;
				now.push_back(v);
				component.erase(--component.end());
				if (u == v) break;
			}
			scc.push_back(now);
		}
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int nodes, edges, c = 1; cin >> nodes >> edges; ++c, val.clear(), key.clear()) {
		if (nodes + edges == 0) break;
		if (c >= 2) puts("");
		Graph graph(nodes);
		int ID = 0;
		for (int i = 0; i < edges; ++i) {
			string s1, s2; cin >> s1 >> s2;
			if (!val.count(s1)) {
				val[s1] = ID;
				key[ID] = s1;
				ID++;
			}
			if (!val.count(s2)) {
				val[s2] = ID;
				key[ID] = s2;
				ID++;
			}
			graph.addEdge(val[s1], val[s2]);
		}
		printf("Calling circles for data set %d:\n", c);
		graph.doTarjan();
		for (int i = 0; i < SIZE(graph.scc); ++i) {
			cout << key[graph.scc[i][0]];
			for (int j = 1; j < SIZE(graph.scc[i]); ++j)
				cout << ", " << key[graph.scc[i][j]];
			cout << endl;
		}
	}
	return 0;
}
