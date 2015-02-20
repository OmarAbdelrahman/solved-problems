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

int const MAXN = 5005;
typedef long long i64;

template<class T> struct edge {
	int f, t; T c;
	edge() { f = t = c = -1; }
	edge(int _f, int _t, T _c)
		: f(_f), t(_t), c(_c) {}
	bool operator < (const edge &e) const {
		return c > e.c;
	}
};

int parent[MAXN];
vector<edge<int> > edge_list;
vector<pair<int, int> > L[MAXN];
vector<int> sz[MAXN];

int find(int x) {
	return x == parent[x] ? x : (parent[x] = find(parent[x]));
}

void init(int n) {
	edge_list.clear();
	for (int i = 0; i < n; i++) {
		L[i].clear();
		sz[i] = vector<int>(1, i);
		parent[i] = i;
	}
}

i64 solve(int edges) {
	sort(edge_list.begin(), edge_list.end());
	i64 result = 0;
	for (int i = 0; i < edge_list.size(); i++) {
		int fp = ::find(edge_list[i].f);
		int tp = ::find(edge_list[i].t);
		if (fp == tp) continue;
		parent[tp] = fp;
		for (int adj = 0; adj < sz[tp].size(); adj++)
			sz[fp].push_back(sz[tp][adj]);
		int inside = INT_MAX;
		int border = 0;
		for (int adj = 0; adj < sz[fp].size(); adj++) {
			int cur_vertex = sz[fp][adj];
			for (int j = 0; j < L[cur_vertex].size(); j++) {
				pair<int, int> next_node = L[cur_vertex][j];
				if (::find(next_node.first) == fp)
					inside = min(inside, next_node.second);
				else
					border = max(border, next_node.second);
			}
		}
		if (inside > border)
			result += (i64) sz[fp].size();
	}
	return result;
}

int main(int argc, char **argv) {
	int T, n, e, a, b, c; scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &n, &e);
		init(n);
		for (int i = 0; i < e; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edge_list.push_back(edge<int>(--a, --b, c));
			L[a].push_back(make_pair(b, c));
			L[b].push_back(make_pair(a, c));
		}
		printf("%ld\n", solve(e));
	}
	return 0;
}