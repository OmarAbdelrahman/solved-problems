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
	edge() { }
	edge(int _f, int _t, int _c)
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

vector<edge> edge_list;

int mst(int nodes) {
	disjoint_set group(nodes);
	sort(edge_list.begin(), edge_list.end());
	int result = 0;
	for (int i = 0; i < edge_list.size(); i++) {
		if (group.equal(edge_list[i].f, edge_list[i].t))
			continue;
		group.join(edge_list[i].f, edge_list[i].t);
		result += edge_list[i].c;
	}
	return result;
}

int main(int argc, char **argv) {
	int nodes, k, m, f, t, c, T = 0;
	while (scanf("%d", &nodes) != EOF) {
		edge_list.clear();
		if (T != 0) puts("");
		for (int i = 0; i < nodes - 1; i++) {
			scanf("%d%d%d", &f, &t, &c);
			edge_list.push_back(edge(f - 1, t - 1, c));
		}
		printf("%d\n", mst(nodes));
		edge_list.clear();
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d%d%d", &f, &t, &c);
			edge_list.push_back(edge(f - 1, t - 1, c));
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &f, &t, &c);
			edge_list.push_back(edge(f - 1, t - 1, c));
		}
		printf("%d\n", mst(nodes));
		T++;
	}
	return 0;
}
