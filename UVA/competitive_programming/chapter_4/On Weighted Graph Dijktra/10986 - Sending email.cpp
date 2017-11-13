#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

typedef long long i64;
const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
#define sz(A) ((int)A.size())
#define all(A) A.begin(), A.end()
#define FOR(i, v, Limit) for (int i = v; i < Limit; i++)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

using namespace std;

struct node_t {
	node_t(int _x, i64 _c):
		x(_x), c(_c) {}
	int x; i64 c;
};

class compare_t {
public:
	bool operator () (const node_t& n1, const node_t& n2) {
		return (n1.c > n2.c);
	}
};

void DoIt(vector<vector<pair<int, i64> > >& graph, vector<i64>& distances, int src, int dest) {
	distances.clear();
	distances.resize(sz(graph), oo);
	vector <bool> visited(sz(graph), false);
	distances[src] = 0;
	priority_queue <node_t, vector <node_t>, compare_t> Q;
	Q.push(node_t(src, 0));
	while (!Q.empty()) {
		int indx = Q.top().x;
		i64 cost = Q.top().c;
		if (visited[indx]) continue;
		visited[indx] = true;
		if (indx == dest) break;
		for (vector<pair<int, i64> >::iterator it = graph[indx].begin(); it != graph[indx].end(); it++) {
			i64 new_cost = cost + it->second;
			if (new_cost < distances[it->first]) {
				distances[it->first] = new_cost;
				Q.push(node_t(it->first, new_cost));
			}
		}
		Q.pop();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int test; scanf("%d", &test);
	for (int turn = 1; test--; turn++) {
		int size, connections;
		int source, destination;
		scanf("%d%d%d%d", &size, &connections, &source, &destination);
		vector<vector<pair<int, i64> > > graph(20001);
		for (int i = 0; i < connections; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			graph[a].push_back(make_pair <int, i64>(b, c));
			graph[b].push_back(make_pair <int, i64>(a, c));
		}
		vector<i64> distances;
		DoIt(graph, distances, source, destination);
		if (distances[destination] == oo)
			printf("Case #%d: unreachable\n", turn);
		else
			printf("Case #%d: %d\n", turn, distances[destination]);
	}
	return 0;
}