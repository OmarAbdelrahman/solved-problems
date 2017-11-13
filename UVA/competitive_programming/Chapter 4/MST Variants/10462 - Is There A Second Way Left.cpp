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

int const MAXE = 210;

struct edge {
	int f, t, c, id;
	edge() { f = t = c = id = -1; }
	edge(int _f, int _t, int _c)
		: f(_f), t(_t), c(_c) {}
	edge(int _f, int _t, int _c, int _id)
		: f(_f), t(_t), c(_c), id(_id) {}
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

pair<vector<edge>, int> mst(int nodes, int edges) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	pair<vector<edge>, int> result;
	for (int i = 0; i < edges; i++) {
		edge_list[i].id = i;
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			result.first.push_back(edge_list[i]);
		}
	}
	if (s.components != 1)
		return make_pair(vector<edge>(), -1);
	return result;
}

int second_mst(int nodes, int edges, int id) {
	disjoint_set s(nodes);
	int result = 0;
	for (int i = 0; i < edges; i++) {
		if (edge_list[i].id == id)
			continue;
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			result += edge_list[i].c;
		}
	}
	if (s.components != 1)
		return 0x3f3f3f3f;
	return result;
}

int main(int argc, char **argv) {
	int T; cin >> T;
	for (int turn = 1; T-- != 0; turn++) {
		int n; cin >> n;
		int e; cin >> e;
		for (int i = 0; i < e; i++) {
			int a, b, c; cin >> a >> b >> c;
			edge_list[i] = edge(a - 1, b - 1, c);
		}
		pair<vector<edge>, int> tree = mst(n, e);
		printf("Case #%d : ", turn);
		if (tree.second == -1)
			puts("No way");
		else {
			int result = 0x3f3f3f3f;
			for (int i = 0; i < tree.first.size(); i++)
				result = min(result, second_mst(n, e, tree.first[i].id));
			if (result == 0x3f3f3f3f)
				puts("No second way");
			else
				printf("%d\n", result);
		}
	}
	return 0;
}