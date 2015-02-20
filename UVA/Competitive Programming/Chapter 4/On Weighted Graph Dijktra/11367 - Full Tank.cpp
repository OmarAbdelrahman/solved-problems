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

int const MAXC = 101;
int const BIG_NUM = 0x3f3f3f3f;

struct state {
	int index;
	int cap;
	int distance;
	state() {}
	state(int i, int c, int d)
		: index(i), cap(c), distance(d) {}
	bool operator < (const state &s) const {
		return distance > s.distance;
	}
};

int solve(int &src, int &trg, int &max_cap, vector<int> &price, vector<vector<state> > &graph) {
	vector<vector<int> > cost(price.size(), vector<int>(max_cap + 1, BIG_NUM));
	cost[src][0] = 0;
	priority_queue<state> q;
	for (q.push(state(src, 0, 0)); !q.empty();) {
		int index = q.top().index;
		int cap = q.top().cap;
		int distance = q.top().distance;
		q.pop();
		if (index == trg)
			return distance;
		if (cost[index][cap] < distance)
			continue;
		if (cap < max_cap && price[index] + distance < cost[index][cap + 1]) {
			cost[index][cap + 1] = price[index] + distance;
			q.push(state(index, cap + 1, price[index] + distance));
		}
		for (int i = 0; i < graph[index].size(); ++i) {
			state next = graph[index][i];
			int needed = cap - next.distance;
			if (needed >= 0) {
				if (distance < cost[next.index][needed]) {
					cost[next.index][needed] = distance;
					q.push(state(next.index, needed, distance));
				}
			}
		}
	}
	return BIG_NUM;
}

int main(int argc, char **args) {
	for (int n, e; scanf("%d%d", &n, &e) != EOF;) {
		vector<int> price(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &price[i]);
		vector<vector<state> > adj(n);
		for (int i = 0; i < e; ++i) {
			int u, v, c; scanf("%d%d%d", &u, &v, &c);
			adj[u].push_back(state(v, 0, c));
			adj[v].push_back(state(u, 0, c));
		}
		int query; scanf("%d", &query);
		while (query-- > 0) {
			int c, u, v; scanf("%d%d%d", &c, &u, &v);
			int result = solve(u, v, c, price, adj);
			if (result >= BIG_NUM)
				puts("impossible");
			else
				printf("%d\n", result);
		}
	}
	return 0;
}