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

int const MAXN = 510;
int const MAXE = MAXN * MAXN;

struct edge {
	int f, t, c;
	edge() { f = t = c = -1; }
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
char node[MAXN][5];

int negative_mod(int a, int b) {
	return (a % b + b) % b;
}

int get_cost(char src[], char trg[]) {
	int result = 0;
	for (int i = 0; i < 4; i++)
		result += min(negative_mod(src[i] - trg[i], 10), negative_mod(trg[i] - src[i], 10));
	return result;
}

int get_edges(int n) {
	int size = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			edge_list[size++] = edge(i, j, get_cost(node[i], node[j]));
	return size;
}

int mst(int nodes, int edges) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	int result = 0;
	for (int i = 0; i < edges; i++) {
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			result += edge_list[i].c;
		}
		if (s.components == 1)
			return result;
	}
	return result;
}

int main(int argc, char **argv) {
	int T, i, n, size, result, min_key; scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%s", node[i]);
		size = get_edges(n);
		result = mst(n, size);
		min_key = 0x3f3f3f3f;
		for (i = 0; i < n; i++)
			min_key = min(min_key, get_cost(node[i], "0000"));
		printf("%d\n", result + min_key);
	}
	return 0;
}