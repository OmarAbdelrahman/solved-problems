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

template<class T> struct edge {
	int f, t; T c;
	edge() { }
	edge(int _f, int _t, T _c)
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

edge<int> edge_list[79800 + 10];

int mst(int nodes, int edges) {
	disjoint_set s(nodes);
	sort(edge_list, edge_list + edges);
	int result = 0;
	for (int i = 0; i < edges; i++)
		if (!s.equal(edge_list[i].f, edge_list[i].t)) {
			s.join(edge_list[i].f, edge_list[i].t);
			result += edge_list[i].c;
		}
	if (s.components != 1)
		return -1;
	return result;
}

int main(int argc, char **argv) {
	for (int n, e, ID = 0; scanf("%d%d", &n, &e); ID = 0) {
		if (n == 0 && e == 0)
			break;
		map<string, int> val;
		for (int i = 0; i < n; i++) {
			string a; cin >> a;
			val[a] = ID++;
		}
		for (int i = 0; i < e; i++) {
			string a, b; int c; cin >> a >> b >> c;
			edge_list[i] = edge<int>(val[a], val[b], c);
		}
		string a; cin >> a;
		int result = mst(n, e);
		if (result == -1) puts("Impossible"); else cout << result << endl;

	}
	return 0;
}