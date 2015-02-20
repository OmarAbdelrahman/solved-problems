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

int const MAXN = 10000 + 10;
int const MAXE = 100000 + 10;

struct edge {
	int f, t, c;
	edge() { f = t = c = -1; }
	edge(int _f, int _t, int _c)
		: f(_f), t(_t), c(_c) {}
	bool operator < (const edge &e) const {
		return c > e.c;
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

int mst(int nodes, int edges) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	int result = 0;
	for (int i = 0; i < edges; i++)
		result += edge_list[i].c;
	for (int i = 0; i < edges; i++) {
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			result -= edge_list[i].c;
		}
		if (s.components == 1)
			break;
	}
	return result;
}

int main(int argc, char **argv) {
	int T, n, e, a, b, c; scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &e);
		for (int i = 0; i < e; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edge_list[i] = edge(a - 1, b - 1, c);
		}
		printf("%d\n", mst(n, e));
	}
	return 0;
}