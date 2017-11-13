#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int const MAXE = 1000000 + 5;
typedef long long i64;
#define next_int() ({int __t; scanf("%d", &__t); __t;})

struct edge {
	int f, t, c;
	edge() { f = t = c = 0; }
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

edge edge_list[MAXE];

int mst(int nodes, int edges) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	for (int i = 0; i < edges; i++) {
		if (!s.equal(edge_list[i].f, edge_list[i].t))
			s.join(edge_list[i].f, edge_list[i].t);
		if (s.components == 1)
			return edge_list[i].c;
	}
	return -1;
}

int main(int argc, char **argv) {
	int n, e, result, f, t, c;
	while (true) {
		n = next_int();
		e = next_int();
		if (n == 0 && e == 0)
			break;
		for (int i = 0; i < e; i++) {
			f = next_int();
			t = next_int();
			c = next_int();
			edge_list[i] = edge(f, t, c);
		}
		result = mst(n, e);
		if (result == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", result);
	}
	return 0;
}

