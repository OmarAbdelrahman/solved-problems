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

int const MAXN = 755;
int const MAXE = MAXN * MAXN;

struct edge {
	int f, t; double c;
	edge() { f = t = c = -1; }
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

double dist(double x1, double y1, double x2, double y2) {
	return hypot(x1 - x2, y1 - y2);
}

edge edge_list[MAXE];
edge cur_highway[1010];
double x[MAXN], y[MAXN];

vector<edge> partial_mst(int nodes, int edges, int highway_size) {
	disjoint_set s(nodes);
	for (int i = 0; i < highway_size; i++)
		s.join(cur_highway[i].f, cur_highway[i].t);
	if (s.components == 1)
		return vector<edge>();
	sort(edge_list, edge_list + edges);
	vector<edge> result;
	for (int i = 0; i < edges; i++) {
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			result.push_back(edge_list[i]);
		}
		if (s.components == 1)
			break;
	}
	return result;
}

int main(int argc, char **argv) {
	int T; cin >> T;
	while (T-- != 0) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		int size = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				edge_list[size++] = edge(i, j, dist(x[i], y[i], x[j], y[j]));
		int highway_size; cin >> highway_size;
		for (int i = 0; i < highway_size; i++) {
			cin >> cur_highway[i].f >> cur_highway[i].t;
			--cur_highway[i].f;
			--cur_highway[i].t;
		}
		vector<edge> result = partial_mst(n, size, highway_size);
		if (result.size() == 0)
			puts("No new highways need");
		else
			for (int i = 0; i < result.size(); i++)
				printf("%d %d\n", result[i].f + 1, result[i].t + 1);
		if (T != 0) puts("");
	}
	return 0;
}