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

int const MAXN = 1000 + 5;
int const MAXE = 25000 + 5;

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

edge edge_list[MAXE];

vector<int> mst(int nodes, int edges) {
	disjoint_set group(nodes);
	sort(edge_list, edge_list + edges);
	vector<int> result;
	for (int i = 0; i < edges; i++) {
		if (group.equal(edge_list[i].f, edge_list[i].t)) {
			result.push_back(edge_list[i].c);
			continue;
		}
		group.join(edge_list[i].f, edge_list[i].t);
	}
	return result;
}

int main(int argc, char **argv) {
	int n, e, f, t, c;
	while (scanf("%d%d", &n, &e)) {
		if (n == 0 && e == 0)
			break;
		for (int i = 0; i < e; i++) {
			scanf("%d%d%d", &f, &t, &c);
			edge_list[i] = edge(f, t, c);
		}
		vector<int> result = mst(n, e);
		if (result.size()) {
			printf("%d", result[0]);
			for (int i = 1; i < result.size(); i++)
				printf(" %d", result[i]);
		} else
			printf("forest");
		puts("");
	}
	return 0;
}
