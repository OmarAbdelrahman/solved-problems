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

typedef unsigned int uint;

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

struct edge {
	int from, to; uint cost;
	edge() {}
	edge(int f, int t, int c)
		: from(f), to(t), cost(c) {}
	bool operator < (const edge& e) const {
		return cost < e.cost;
	}
};

edge edge_list[300000 + 2];

static uint mst(int nodes, int edges) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	uint result = 0;
	for (int i = 0; i < edges; ++i) {
		if (s.equal(edge_list[i].from, edge_list[i].to))
			continue;
		s.join(edge_list[i].from, edge_list[i].to);
		result += edge_list[i].cost;
		if (s.components == 1)
			break;
	}
	return result;
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		int price; scanf("%d", &price);
		int nodes; scanf("%d", &nodes);
		int edges; scanf("%d", &edges);
		for (int i = 0; i < edges; ++i) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			edge_list[i] = edge(a - 1, b - 1, c);
		}
		cout << mst(nodes, edges) * price << endl;
	}
	return 0;
}