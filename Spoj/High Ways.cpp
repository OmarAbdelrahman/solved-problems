/*
TASK: ditch
LANG: C++
 */

#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
#include <bitset>
#include <complex>
#include <cassert>
#include <numeric>

using namespace std;

#define eps                           (1e-12)
#define oo                            (int)1e9
#define sz(A)                         ((int)A.size())

vector < vector < pair <int, int> > > graph;
vector <int> distances;

struct State {
	int x, c;
	State() {}
	State(int xx, int cc) {
		x = xx, c = cc;
	}
};

class Compare {
public:
	bool operator () (const State s1, const State s2) {
		return s1.c > s2.c;
	}
};

void dijkastra(int source, int sink = -1) {
	distances.clear();

	vector <bool> visited(graph.size(),false);
	distances.resize(graph.size(),oo);

	priority_queue <State, vector <State>, Compare> d;
	d.push(State(source, 0));
	distances[source] = 0;

	while (!d.empty()) {
		int cost = d.top().c;
		int indx = d.top().x;
		d.pop();

		if (visited[indx])
			continue;

		visited[indx] = true;

		if (indx == sink)
			return;

		for (int i = 0; i < sz(graph[indx]); ++i) {
			int tempdist = cost + graph[indx][i].second;
			if (tempdist < distances[graph[indx][i].first]) {
				distances[graph[indx][i].first] = tempdist;
				d.push(State(graph[indx][i].first, tempdist));
			}
		}
	}
}

int t, n, m, a, b, _a, _b, c;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &a, &b);
		graph.resize(n);

		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &_a, &_b, &c);
			graph[_a - 1].push_back(pair <int, int>(_b - 1, c));
			graph[_b - 1].push_back(pair <int, int>(_a - 1, c));
		}
		dijkastra(a - 1, b - 1);

		(distances[b - 1] == oo) ? puts("NONE") : printf("%d\n", distances[b - 1]);

		graph.clear();
	}
	return 0;
}
