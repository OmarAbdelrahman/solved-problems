/*
ID: 1010
PROG: game1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <limits.h>
using namespace std;

typedef pair<double, int> state;
typedef vector<state> List;
typedef vector<List> AdjacentList;
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

AdjacentList graph;

vector<double> f(int src = 0) {
	vector<double> dist(graph.size(), INT_MIN);
	vector<bool> vis(graph.size(), false);
	dist[src] = 1.;
	priority_queue<state, List, less<state> > q;
	q.push(state(1., src));
	while (!q.empty()) {
		double cost = q.top().first;
		int indx = q.top().second;
		q.pop();
		if (vis[indx]) continue;
		vis[indx] = true;
		FOREACH(val, graph[indx]) {
			double newc = cost * val->first;
			if (newc > dist[val->second]) {
				dist[val->second] = newc;
				q.push(state(newc, val->second));
			}
		}
	}
	return dist;
}

double _main(int vertex, int edges) {
	graph = AdjacentList(vertex);
	for (int i = 0; i < edges; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(c / 100., b - 1));
		graph[b - 1].push_back(make_pair(c / 100., a - 1));
	}
	return f()[vertex - 1] * 100;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	int vertex, edges;
	while (cin >> vertex >> edges && vertex) {
		printf("%6lf percent\n", _main(vertex, edges));
	}
	return 0;
}