#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE(a) ((int)a.size())

struct edge {
	int f, t;
	double d;
	edge(int _f, int _t, double _d):
		f(_f), t(_t), d(_d) {}
	bool operator < (const edge &e) const {
		return d < e.d;
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

double dist(int x1, int x2, int y1, int y2) {
	return hypot(x1 - x2, y1 - y2);
}

pair<int, pair<int, int> > kruskal(vector<edge> &edge_list, int nodes, int r) {
	disjoint_set tree(nodes);
	sort(edge_list.begin(), edge_list.end());
	double roads = 0;
	double rail_roads = 0;
	int states = 0;
	for (int i = 0; i < SIZE(edge_list); i++) {
		if (tree.equal(edge_list[i].f, edge_list[i].t))
			continue;
		tree.join(edge_list[i].f, edge_list[i].t);
		if (edge_list[i].d <= r)
			roads += edge_list[i].d;
		else {
			rail_roads += edge_list[i].d;
			states++;
		}
	}
	return make_pair(states, make_pair((int) round(roads), (int) round(rail_roads)));
}

int main(int argc, char **argv) {
	int T; cin >> T;
	for (int c = 1; T-- != 0; c++) {
		int cities, r; cin >> cities >> r;
		vector<edge> edge_list;
		vector<pair<int, int> > C(cities);
		for (int i = 0; i < cities; i++)
			cin >> C[i].first >> C[i].second;
		for (int i = 0; i < cities; i++)
			for (int j = i + 1; j < cities; j++)
				edge_list.push_back(edge(i, j, dist(C[i].first, C[j].first, C[i].second, C[j].second)));
		pair<int, pair<int, int> > res = kruskal(edge_list, cities, r);
		printf("Case #%d: %d %d %d\n", c, res.first + 1, res.second.first, res.second.second);
	}
	return 0;
}

