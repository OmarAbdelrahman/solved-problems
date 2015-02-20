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

template<class T> struct edge {
	int from, to; T cost;
	edge() { from = to = cost = -1; }
	edge(int f, int t, T c)
		: from(f), to(t), cost(c) {}
	bool operator < (const edge& e) const {
		return cost < e.cost;
	}
};

vector<edge<int> > edge_list;

int mst(int nodes) {
	disjoint_set s(nodes);
	sort(edge_list.begin(), edge_list.end());
	int result = 0;
	for (int i = 0; i < edge_list.size(); ++i) {
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
	int TC, nodes, i, q, to, cost; scanf("%d", &TC);
	char city[50];
	while (TC-- > 0) {
		edge_list.clear();
		scanf("%d", &nodes);
		for (i = 0; i < nodes; ++i) {
			scanf("%s", city);
			scanf("%d", &q);
			while (q-- > 0) {
				scanf("%d%d", &to, &cost);
				edge_list.push_back(edge<int>(i, to - 1, cost));
			}
		}
		printf("%d\n", mst(nodes));
	}
	return 0;
}