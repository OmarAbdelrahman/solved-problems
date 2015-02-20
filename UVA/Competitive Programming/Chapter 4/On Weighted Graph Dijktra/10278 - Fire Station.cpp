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

int const MAXF = 105;
int const MAXN = 505;
int const BIG_NUM = 0x3f3f3f3f;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

struct state {
	state() {}
	state(int i, int c)
		: index(i), cost(c) {}
	bool operator < (const state &s) const {
		return cost > s.cost;
	}
	int index, cost;
};

vector<int> solve(int src, vector<bool> &is_station, vector<vector<state> > &G) {
	vector<int> distance(G.size(), BIG_NUM);
	vector<bool> visited(G.size(), false);
	priority_queue<state> heap;
	REP(i, is_station.size()) {
		if (is_station[i] && i != src) {
			distance[i] = 0;
			heap.push(state(i, 0));
		}
	}
	distance[src] = 0;
	for (heap.push(state(src, 0)); !heap.empty();) {
		int index = heap.top().index;
		int cost = heap.top().cost;
		heap.pop();
		if (visited[index])
			continue;
		visited[index] = true;
		REP(i, G[index].size()) {
			state next = G[index][i];
			if (cost + next.cost < distance[next.index]) {
				distance[next.index] = cost + next.cost;
				heap.push(state(next.index, cost + next.cost));
			}
		}
	}
	return distance;
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		int fire; scanf("%d", &fire);
		int nodes; scanf("%d", &nodes);
		vector<bool> is_station(nodes, false);
		REP(i, fire) {
			int a; scanf("%d", &a);
			is_station[a - 1] = true;
		}
		vector<vector<state> > graph(nodes);
		cin.ignore();
		for (string info; getline(cin, info) && info != "";) {
			stringstream sin(info);
			int a, b, c; sin >> a >> b >> c;
			graph[a - 1].push_back(state(b - 1, c));
			graph[b - 1].push_back(state(a - 1, c));
		}
		int min_index = -1;
		int min_max = BIG_NUM;
		REP(i, nodes) {
			vector<int> distance = solve(i, is_station, graph);
			int big = distance[0];
			FOR(j, 1, distance.size())
				big = max(big, distance[j]);
			if (big < min_max) {
				min_max = big;
				min_index = i + 1;
			}
		}
		printf("%d\n", min_index);
		if (TC > 0)
			printf("\n");
	}
	return 0;
}