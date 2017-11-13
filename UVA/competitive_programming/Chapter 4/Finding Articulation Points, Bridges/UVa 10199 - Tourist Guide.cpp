#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
int const MAX = 100 + 5;

map<string, int> ID;
string city[MAX];

struct Bridge {
	vector<vector<int> > L;
	vector<int> low, num;
	vector<int> parent;
	vector<bool> articulation;
	int counter;
	int root, rootChildren;

	Bridge(int n) {
		L = vector<vector<int> >(n);
		num = vector<int>(n, -1);
		low = parent = vector<int>(n, 0);
		articulation = vector<bool>(n, false);
		rootChildren = counter = 0;
		root = -1;
	}

	void addEdge(int a, int b, bool u = false) {
		L[a].push_back(b);
		if (u)
			L[b].push_back(a);
	}

	void detectBridges() {
		for (int i = 0; i < SIZE(L); ++i)
			if (num[i] == -1) {
				root = i;
				rootChildren = 0;
				getBridges(i);
				articulation[root] = rootChildren > 1;
			}
	}

	void getBridges(int u) {
		low[u] = num[u] = counter++;
		for (int i = 0; i < SIZE(L[u]); ++i) {
			int v = L[u][i];
			if (num[v] == -1) {
				parent[v] = u;
				if (u == root) ++rootChildren;
				getBridges(v);
				if (low[v] >= num[u])
					articulation[u] = true;
				if (low[v] > num[u]) {
					// bridges
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
	bool first = true;
	for (int nodes, c = 1; cin >> nodes && nodes; ++c, first = false) {
		if (!first) puts("");
		int index = 0;
		for (int i = 0; i < nodes; ++i) {
			cin >> city[i];
			ID[city[i]] = index++;
		}
		int edges; cin >> edges;
		Bridge graph(nodes);
		for (int i = 0; i < edges; ++i) {
			string src, trg; cin >> src >> trg;
			int a = ID[src], b = ID[trg];
			graph.addEdge(a, b, true);
		}
		graph.detectBridges();
		vector<string> artVertex;
		for (int i = 0; i < nodes; ++i)
			if (graph.articulation[i])
				artVertex.push_back(city[i]);
		sort(artVertex.begin(), artVertex.end());
		printf("City map #%d: %d camera(s) found\n", c, SIZE(artVertex));
		for (int i = 0; i < SIZE(artVertex); ++i)
			cout << artVertex[i] << endl;
	}
	return 0;
}

