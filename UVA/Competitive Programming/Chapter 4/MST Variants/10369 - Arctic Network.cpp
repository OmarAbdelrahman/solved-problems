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

int const MAXE = 500 * 500 + 5;
int const MAXQ = 10000 + 5;

struct edge {
	int f, t; double c;
	edge() { f = t = c = 0; }
	edge(int _f, int _t, double _c)
		: f(_f), t(_t), c(_c) {}
	bool operator < (const edge &e) const {
		return c < e.c;
	}
};

struct disjoint_set {
	int *parent;
	int *rank;
	int components;

	disjoint_set(int n) {
		parent = new int[n];
		rank = new int[n];
		components = n;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find(int s) {
		return parent[s] == s ? s : find(parent[s]);
	}

	bool equal(int s1, int s2) {
		return find(s1) == find(s2);
	}

	void join(int s1, int s2) {
		int p1 = find(s1);
		int p2 = find(s2);
		if (p1 == p2) return;
		if (rank[p1] == rank[p2])
			++rank[p1];
		if (rank[p1] < rank[p2])
			swap(p1, p2);
		parent[p2] = p1;
		--components;
	}
};

edge edge_list[MAXE];
double x[MAXQ], y[MAXQ];

double dist(double x1, double y1, double x2, double y2) {
	return hypot(x1 - x2, y1 - y2);
}

double mst(int nodes, int edges, int satellites) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	for (int i = 0; i < edges; i++) {
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			if (s.components == satellites)
				return edge_list[i].c;
		}
	}
	return edge_list[edges - 1].c;
}

int main(int argc, char **argv) {
	int T; cin >> T;
	while (T-- != 0) {
		int satellites; cin >> satellites;
		int nodes; cin >> nodes;
		for (int i = 0; i < nodes; i++)
			cin >> x[i] >> y[i];
		int index = 0;
		for (int i = 0; i < nodes; i++)
			for (int j = i + 1; j < nodes; j++)
				edge_list[index++] = edge(i, j, dist(x[i], y[i], x[j], y[j]));
		printf("%.2lf\n", mst(nodes, index, satellites));
	}
	return 0;
}