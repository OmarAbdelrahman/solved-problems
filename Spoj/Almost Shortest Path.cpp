/*
TASK: ditch
LANG: C++
 */

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdio.h>
#include <map>
#include <cmath>
#include <set>

using namespace std;

#define eps                           (1e-12)
#define oo                            (1 << 29)
#define All(A)                        A.begin(), A.end()
#define init(A, B)                    memset(A, B, sizeof(A))
#define foreach(i, c)                 for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;

struct node_t {
	node_t(int _x, int _c):
		x(_x), c(_c) {}
	int x, c;
};

class compare_t {
public:
	bool operator () (const node_t& n1, const node_t& n2) {
		return (n1.c > n2.c);
	}
};

void Di(AdjacentList& graph, vector<int>& distances,int src, int sink = -1) {
	distances.clear();
	distances.resize(graph.size(), oo);
	vector<bool> visited(graph.size(), false);
	priority_queue<node_t, vector<node_t>, compare_t> q;
	q.push(node_t(src, 0));
	distances[src] = 0;
	while (!q.empty()) {
		int indx = q.top().x;
		int cost = q.top().c;
		q.pop();
		if (visited[indx]) continue;
		visited[indx] = true;
		if (indx == sink) break;
		foreach (it, graph[indx]) {
			int newcost = cost + it->second;
			if (newcost < distances[it->first]) {
				distances[it->first] = newcost;
				q.push(node_t(it->first, newcost));
			}
		}
	}
}

void Remove(AdjacentMatrix& matrix, vector <int>& dist, int src) {
	for (int i = 0; i < (int)matrix.size(); i++) {
		if (!matrix[src][i]) continue;
		if (matrix[src][i] != dist[src] - dist[i]) continue;
		matrix[src][i] = 0;
		Remove(matrix, dist, i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
#endif
	int n, m;
	while (scanf("%d%d", &n, &m) && (n | m)) {
		int src, sink;
		scanf("%d%d", &src, &sink);
		AdjacentList graph(n);
		vector <int> distances;
		AdjacentMatrix matrix(n, vector <int>(n, 0));
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			graph[b].push_back(pair<int, int>(a, c));
			matrix[a][b] = c;
		}
		Di(graph, distances, sink);
		Remove(matrix, distances, src);
		graph.clear(); graph = AdjacentList(n);
		for (int i = 0; i < (int)matrix.size(); i++)
			for (int j = 0; j < (int)matrix.size(); j++) {
				if (!matrix[i][j]) continue;
				graph[i].push_back(pair <int, int>(j, matrix[i][j]));
			}
		Di(graph, distances, src, sink);
		(distances[sink] >= oo) ? printf("%d\n", -1) : printf("%d\n", distances[sink]);
	}
	return 0;
}