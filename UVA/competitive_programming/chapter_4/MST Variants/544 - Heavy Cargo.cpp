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

int const MAXN = 755;
int const MAXE = MAXN * MAXN;

struct edge {
	int f, t; double c;
	edge() { f = t = c = -1; }
	edge(int _f, int _t, double _c)
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

map<string, int> val;
map<int, string> key;
vector<edge> edge_list;

int mst(int nodes, int from, int to) {
	disjoint_set s(nodes);
	sort(edge_list.begin(), edge_list.end());
	for (int i = 0; i < edge_list.size(); i++) {
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			if (s.equal(from, to))
				return edge_list[i].c;
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	for (int n, e, turn = 1; cin >> n >> e; turn++) {
		if (n == 0 && e == 0)
			break;
		int ID = 0;
		val.clear();
		key.clear();
		edge_list.clear();
		for (int i = 0; i < e; i++) {
			string a, b; int c; cin >> a >> b >> c;
			if (!val.count(a)) {
				val[a] = ID;
				key[ID] = a;
				ID++;
			}
			if (!val.count(b)) {
				val[b] = ID;
				key[ID] = b;
				ID++;
			}
			edge_list.push_back(edge(val[a], val[b], c));
		}
		string a, b; cin >> a >> b;
		printf("Scenario #%d\n%d tons\n\n", turn, mst(n, val[a], val[b]));
	}
	return 0;
}