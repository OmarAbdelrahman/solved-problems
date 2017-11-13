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
	int f, t;
	edge(int _f, int _t)
		: f(_f), t(_t) {}
};

int value[105];
bool visited[105];

static bool is_path(int cur_node, int nodes, vector<edge>& edges) {
	if (cur_node == nodes - 1)
		return true;
	visited[cur_node] = true;
	bool reached = false;
	for (int i = 0; i < edges.size(); i++)
		if (edges[i].f == cur_node && !visited[edges[i].t])
			reached |= is_path(edges[i].t, nodes, edges);
	return reached;
}

static bool reach(int nodes, vector<edge>& edges) {
	vector<int> distance(nodes, -integer::BIG_NUM);
	distance[0] = 100;
	for (int i = 0; i < nodes; i++)
		for (int j = 0; j < edges.size(); j++) {
			int f = edges[j].f, t = edges[j].t;
			if (distance[f] > 0 && distance[f] + value[t] > distance[t])
				distance[t] = distance[f] + value[t];
		}
	for (int i = 0; i < edges.size(); i++) {
		int f = edges[i].f, t = edges[i].t;
		if (distance[f] > 0 && distance[f] + value[t] > distance[t])
			if (is_path(f, nodes, edges)) {
				distance[nodes - 1] = 100;
				break;
			}
	}
	return distance[nodes - 1] > 0;
}

int main(int argc, char **args) {
	io::read_file();
	for (int nodes = io::next<int>(); nodes >= 0; nodes = io::next<int>()) {
		vector<edge> edges;
		memset(value, 0, sizeof value);
		memset(visited, false, sizeof visited);
		for (int from = 0; from < nodes; from++) {
			value[from] = io::next<int>();
			int out = io::next<int>();
			for (int i = 0; i < out; i++) {
				int to = io::next<int>() - 1;
				edges.push_back(edge(from, to));
			}
		}
		if (reach(nodes, edges)) puts("winnable"); else puts("hopeless");
	}
	return 0;
}