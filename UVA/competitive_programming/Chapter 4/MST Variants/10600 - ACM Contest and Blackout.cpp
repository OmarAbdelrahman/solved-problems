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

struct edge {
	int f, t, c;
	edge() { f = t = c = 0; }
	edge(int _f, int _t, int _c)
		: f(_f), t(_t), c(_c) { }
	bool operator < (const edge &e) const {
		return c < e.c;
	}
};

struct disjoint_set {
	vector<int> parent;
	vector<int> rank;
	vector<int> setSize;
	int numSets;

	disjoint_set(int n) {
		parent = vector<int>(n);
		rank = vector<int>(n, 0);
		setSize = vector<int>(n, 1);
		numSets = n;
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int setNum) {
		return parent[setNum] == setNum ? setNum : find(parent[setNum]);
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
		setSize[p1] += setSize[p2];
		--numSets;
	}
};

vector<edge> edge_list;

vector<edge> mst(int nodes) {
	disjoint_set s(nodes);
	sort(edge_list.begin(), edge_list.end());
	vector<edge> result;
	for (int i = 0; i < edge_list.size(); i++) {
		int f = edge_list[i].f;
		int t = edge_list[i].t;
		if (!s.equal(f, t)) {
			s.join(f, t);
			result.push_back(edge_list[i]);
		}
	}
	return result;
}

int second_mst(int nodes, int cf, int ct) {
	disjoint_set s(nodes);
	int result = 0;
	for (int i = 0; i < edge_list.size(); i++) {
		if (edge_list[i].t == ct && edge_list[i].f == cf)
			continue;
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			result += edge_list[i].c;
		}
	}
	if (s.numSets != 1)
		return 0x3f3f3f3f;
	return result;
}

int main(void) {
	int T; cin >> T;
	while (T-- != 0) {
		int nodes; cin >> nodes;
		int edges; cin >> edges;
		edge_list.clear();
		for (int i = 0; i < edges; i++) {
			int a, b, c; cin >> a >> b >> c;
			edge_list.push_back(edge(a - 1, b - 1, c));
		}
		vector<edge> tree = mst(nodes);
		int s1 = 0, s2 = 0x3f3f3f3f;
		for (int i = 0; i < tree.size(); i++) {
			s2 = min(s2, second_mst(nodes, tree[i].f, tree[i].t));
			s1 += tree[i].c;
		}
		printf("%d %d\n", s1, s2 == 0x3f3f3f3f ? s1 : s2);
	}
	return 0;
}