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

typedef long long int64;

struct io {
	template<class T> static T next() {
		T n; std::cin >> n;
		return n;
	}

	static void read_file() {
#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
#endif
	}
};

struct integer {
	static const int BIG_NUM = 2000000000;
	static const int64 BIG_NUML = 8000000000000000000L;
};

struct edge {
	int f, t, c;
	edge(int _f, int _t, int _c)
		: f(_f), t(_t), c(_c) {}
};

static bool found(int nodes, vector<edge>& edges) {
	vector<int> distance(nodes, integer::BIG_NUM);
	distance[0] = 0;
	for (int i = 0; i < nodes; i++) {
		bool relax = false;
		for (int j = 0; j < edges.size(); j++)
			if (distance[edges[j].f] + edges[j].c < distance[edges[j].t]) {
				distance[edges[j].t] = distance[edges[j].f] + edges[j].c;
				relax = true;
			}
		if (!relax) break;
		if (i == nodes - 1)
			return true;
	}
	return false;
}

int main(int argc, char **args) {
	io::read_file();
	for (int T = io::next<int>(); T-- > 0;) {
		int n = io::next<int>();
		int m = io::next<int>();
		vector<edge> edges;
		for (int i = 0; i < m; i++) {
			int a = io::next<int>();
			int b = io::next<int>();
			int c = io::next<int>();
			edges.push_back(edge(a, b, c));
		}
		if (found(n, edges)) puts("possible"); else puts("not possible");
	}
	return 0;
}