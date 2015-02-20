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

int const MAXE = 100000 + 5;
typedef long long i64;

struct edge {
	int f, t; i64 c;
	edge() { }
	edge(int _f, int _t, i64 _c)
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

pair<i64, int> mst(int nodes, int edges, i64 airport_cost) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	int result = 0;
	for (int i = 0; i < edges; i++) {
		if (edge_list[i].c >= airport_cost)
			break;
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			result += edge_list[i].c;
		}
	}
	return make_pair(result + (airport_cost * (i64) s.components), s.components);
}

int main(int argc, char **argv) {
	int T, n, e, ac, f, t, c; scanf("%d", &T);
	for (int turn = 1; T-- != 0; turn++) {
		scanf("%d%d%d", &n, &e, &ac);
		for (int i = 0; i < e; i++) {
			scanf("%d%d%d", &f, &t, &c);
			edge_list[i] = edge(f - 1, t - 1, (i64) c);
		}
		pair<i64, int> result = mst(n, e, ac);
		cout << "Case #" << turn << ": " << result.first << " " << result.second << endl;
	}
	return 0;
}
