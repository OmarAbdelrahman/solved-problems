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

int const MAXN = 110;
int const MAXE = 100000 + 10;

template<class T> struct edge {
	int f, t; T c;
	edge() { f = t = c = -1; }
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

double x[MAXN], y[MAXN];
vector<edge<double> > edge_list;

double dist(double x1, double y1, double x2, double y2) {
	return hypot(x1 - x2, y1 - y2);
}

double mst(int nodes) {
	disjoint_set s(nodes);
	sort(edge_list.begin(), edge_list.end());
	double result = 0;
	for (int i = 0; i < edge_list.size(); i++) {
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
	int T, n; scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		edge_list = vector<edge<double> >();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				edge_list.push_back(edge<double>(i, j, dist(x[i], y[i], x[j], y[j])));
		printf("%.2lf\n", mst(n));
		if (T != 0) puts("");
	}
	return 0;
}