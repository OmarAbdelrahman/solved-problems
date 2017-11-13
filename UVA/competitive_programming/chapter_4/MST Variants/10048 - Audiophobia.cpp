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

int const MAXE = 1000 + 5;
int const MAXQ = 10000 + 5;

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
bool visited[MAXQ];
int x[MAXQ], y[MAXQ];
int result[MAXQ];

void mst(int nodes, int edges, int queries) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	for (int i = 0; i < edges; i++)
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			for (int j = 0; j < queries; j++)
				if (!visited[j]) {
					if (s.equal(x[j], y[j])) {
						result[j] = edge_list[i].c;
						visited[j] = true;
					}
				}
		}
}

int main(int argc, char **argv) {
	int n, e, q, f, t, c;
	for (int turn = 0; cin >> n >> e >> q; turn++) {
		if (n == 0 && e == 0 && q == 0)
			break;
		if (turn > 0) puts("");
		fill(result, result + MAXQ, -1);
		fill(visited, visited + MAXQ, false);
		for (int i = 0; i < e; i++) {
			cin >> f >> t >> c;
			edge_list[i] = edge(f - 1, t - 1, c);
		}
		for (int i = 0; i < q; i++) {
			cin >> x[i] >> y[i];
			--x[i];
			--y[i];
		}
		mst(n, e, q);
		printf("Case #%d\n", turn + 1);
		for (int i = 0; i < q; i++)
			result[i] == -1 ? puts("no path") : printf("%d\n", result[i]);
	}
	return 0;
}

