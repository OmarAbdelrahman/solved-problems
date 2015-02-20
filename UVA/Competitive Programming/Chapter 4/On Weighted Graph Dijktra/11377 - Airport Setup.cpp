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

int const MAXN = 2005;
int const BIG_NUM = 1 << 28;

struct io_utilis {
	template<class T> static T next() {
		T n; cin >> n;
		return n;
	}
};

struct state {
	state() { index = cost = -1; }
	state(int i, int c)
		: index(i), cost(c) {}
	bool operator < (const state& s) const {
		return cost > s.cost;
	}
	int index, cost;
};

vector<vector<int> > L;

static int solve(int src, int trg, vector<bool> is_airport) {
	vector<int> dist(L.size(), BIG_NUM);
	vector<bool> visited(L.size(), false);
	priority_queue<state> q;
	for (q.push(state(src, 0)), dist[src] = 0; !q.empty();) {
		int index = q.top().index;
		int cost = q.top().cost;
		q.pop();
		if (index == trg)
			return cost;
		if (visited[index])
			continue;
		visited[index] = true;
		for (int i = 0; i < L[index].size(); ++i) {
			int next = L[index][i];
			int newc = cost + (is_airport[next] ? 0 : 1);
			if (newc < dist[next]) {
				dist[next] = newc;
				q.push(state(next, newc));
			}
		}
	}
	return -1;
}

int main(int argc, char **args) {
	int TC = io_utilis::next<int>();
	for (int cases = 1; TC-- > 0; ++cases) {
		L = vector<vector<int> >(io_utilis::next<int>());
		int edges = io_utilis::next<int>();
		vector<bool> is_airport(L.size(), false);
		int airports = io_utilis::next<int>();
		for (int i = 0; i < airports; ++i) 
			is_airport[io_utilis::next<int>() - 1] = true;
		for (int i = 0; i < edges; ++i) {
			int a = io_utilis::next<int>();
			int b = io_utilis::next<int>();
			L[a - 1].push_back(b - 1);
			L[b - 1].push_back(a - 1);
		}
		int query = io_utilis::next<int>();
		printf("Case %d:\n", cases);
		while (query-- > 0) {
			int src = io_utilis::next<int>() - 1;
			int trg = io_utilis::next<int>() - 1;
			int result = solve(src, trg, is_airport);
			if (result > -1 && src != trg)
				result += (is_airport[src] ? 0 : 1);
			printf("%d\n", result);
		}
		printf("\n");
	}
	return 0;
}