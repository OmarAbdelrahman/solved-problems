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

int const MAXD = 10005;
int const BIG_NUM = INT_MAX;

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

int dist[MAXD];
int visited[MAXD], ID;
vector<state> graph[MAXD];
int nodes, to, cost, conn;
int query;
map<string, int> value;
string str, f, t;

int solve(int src, int trg) {
	memset(visited, false, sizeof(visited));
	fill(dist, dist + (int) value.size(), BIG_NUM);
	dist[src] = 0;
	priority_queue<state> q;
	for (q.push(state(src, 0)); !q.empty();) {
		int index = q.top().index;
		int cost = q.top().cost;
		q.pop();
		if (index == trg)
			return cost;
		if (visited[index])
			continue;
		visited[index] = true;
		REP(i, graph[index].size()) {
			state next = graph[index][i];
			if (cost + next.cost < dist[next.index]) {
				dist[next.index] = cost + next.cost;
				q.push(state(next.index, cost + next.cost));
			}
		}
	}
	return dist[trg];
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%d", &nodes);
		ID = 0;
		REP(i, nodes) graph[i].clear();
		value.clear();
		while (nodes-- > 0) {
			cin >> str;
			if (value.find(str) == value.end()) {
				value[str] = ID++;
			}
			scanf("%d", &conn);
			while (conn-- > 0) {
				scanf("%d%d", &to, &cost);
				graph[ID - 1].push_back(state(to - 1, cost));
			}
		}
		scanf("%d", &query);
		while (query-- > 0) {
			cin >> f >> t;
			printf("%d\n", solve(value[f], value[t]));
		}
	}
	return 0;
}