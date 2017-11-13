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

int const BIG_NUM = 0x3f3f3f3f;

struct state {
	int index;
	int cost;
	state() {}
	state(int i, int c)
		: index(i), cost(c) {}
	bool operator < (const state &s) const {
		return cost > s.cost;
	}
};

void solve(int src, int trg, vector<int> parent, vector<int> distance, vector<bool> visited, vector<vector<state> > &G) {
	distance[src] = 0;
	priority_queue<state> q;
	for (q.push(state(src, 0)); !q.empty();) {
		int index = q.top().index;
		int cost = q.top().cost;
		q.pop();
		if (index == trg)
			break;
		if (visited[index])
			continue;
		visited[index] = true;
		for (int i = 0; i < G[index].size(); ++i) {
			state next = G[index][i];
			int newc = cost + next.cost;
			if (newc < distance[next.index]) {
				distance[next.index] = newc;
				q.push(state(next.index, newc));
				parent[next.index] = index;
			}
		}
	}
	stack<int> path;
	int node = trg;
	do {
		path.push(node);
		node = parent[node];
	} while (node >= 0);
	printf("Path =");
	for (; !path.empty(); path.pop())
		printf(" %d", path.top() + 1);
	printf("; %d second delay\n", distance[trg]);
}

int main(int argc, char **args) {
	for (int nodes, TC = 1; scanf("%d", &nodes) && nodes > 0; ++TC) {
		vector<vector<state> > graph(nodes);
		for (int i = 0; i < nodes; ++i) {
			int pairs; scanf("%d", &pairs);
			while (pairs-- > 0) {
				int a, b; scanf("%d%d", &a, &b);
				graph[i].push_back(state(a - 1, b));
			}
		}
		printf("Case %d: ", TC);
		int src, trg; scanf("%d%d", &src, &trg);
		solve(src - 1, trg - 1, vector<int>(nodes, -1), vector<int>(nodes, BIG_NUM), vector<bool>(nodes, false), graph);
	}
	return 0;
}