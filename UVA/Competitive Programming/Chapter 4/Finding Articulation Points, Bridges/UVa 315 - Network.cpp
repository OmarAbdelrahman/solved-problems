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

typedef long long int64;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100 + 5;

vector<int> parse(string str) {
	stringstream sin(str);
	vector<int> v;
	for (int n; sin >> n; v.push_back(n));
	return v;
}

struct Bridge {
	static int const WHITE = -1;
	static int const BLACK = +1;
	static int const GREY = 0;

	vector<vector<int> > L;
	vector<int> low, num;
	vector<int> parent;
	vector<bool> articulation;
	int root, rootChildren;
	int counter;
	vector<pair<int, int> > bridges;

	Bridge(int n) {
		L = vector<vector<int> >(n);
		num = vector<int>(n, WHITE);
		low = vector<int>(n, GREY);
		parent = vector<int>(n, GREY);
		articulation = vector<bool>(n, false);
		bridges.clear();
		counter = rootChildren = 0;
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
				if (low[v] > num[u])
					bridges.push_back(make_pair(u, v));
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
	bool visited[MAX][MAX];
	for (int nodes; cin >> nodes && nodes;) {
		cin.ignore();
		Bridge graph(nodes);
		fill(visited[0], visited[nodes], false);
		for (string s; getline(cin, s) && s != "0";) {
			vector<int> conn = parse(s);
			int a = conn[0] - 1;
			for (int i = 1; i < SIZE(conn); ++i) {
				int b = conn[i] - 1;
				if (visited[a][b] || visited[b][a])
					continue;
				visited[a][b] = true;
				visited[b][a] = true;
				graph.addEdge(a, b, true);
			}
		}
		graph.detectBridges();
		int cnt = 0;
		for (int i = 0; i < nodes; ++i)
			cnt += graph.articulation[i];
		cout << cnt << endl;
	}
	return 0;
}

