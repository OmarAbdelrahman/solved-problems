#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())

struct Bridge {
	static int const WHITE = -1;
	static int const BLACK = +1;
	static int const GREY = 0;

	vector<vector<int> > L;
	vector<int> low, num;
	vector<int> parent;
	vector<bool> articulation;
	int root, rootChildren;
	int counter, bcount;
	vector<vector<int> > bridges;

	Bridge(int n) {
		L = vector<vector<int> >(n);
		num = vector<int>(n, WHITE);
		low = vector<int>(n, GREY);
		parent = vector<int>(n, GREY);
		articulation = vector<bool>(n, false);
		bridges = vector<vector<int> >(n, vector<int>(n, 0));
		counter = rootChildren = bcount = 0;
		root = -1;
	}

	void addEdge(int a, int b, bool undirected = false) {
		L[a].push_back(b);
		if (undirected)
			L[b].push_back(a);
	}

	void detectBridges() {
		for (int i = 0; i < SIZE(L); ++i)
			if (num[i] == WHITE) {
				root = i;
				rootChildren = 0;
				markBridges(i);
				articulation[root] = rootChildren > 1;
			}
	}

	void markBridges(int u) {
		low[u] = num[u] = counter++;
		for (int i = 0; i < SIZE(L[u]); ++i) {
			int v = L[u][i];
			if (num[v] == WHITE) {
				parent[v] = u;
				if (u == root) ++rootChildren;
				markBridges(v);
				if (low[v] >= num[u])
					articulation[u] = true;
				if (low[v] > num[u]) {
					bridges[u][v] = bridges[v][u] = true;
					++bcount;
				}
				low[u] = min(low[u], low[v]);
			} else if (v != parent[u])
				low[u] = min(low[u], num[v]);
		}
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int nodes; cin >> nodes; ) {
		Bridge graph(nodes);
		for (int i = 0; i < nodes; ++i) {
			int src, connections;
			scanf("%d (%d)", &src, &connections);
			for (int j = 0; j < connections; ++j) {
				int trg; cin >> trg;
				graph.addEdge(src, trg, true);
			}
		}
		graph.detectBridges();
		printf("%d critical links\n", graph.bcount);
		for (int i = 0; i < nodes; ++i)
			for (int j = i + 1; j < nodes; ++j)
				if (graph.bridges[i][j])
					printf("%d - %d\n", i, j);
		puts("");
	}
	return 0;
}

