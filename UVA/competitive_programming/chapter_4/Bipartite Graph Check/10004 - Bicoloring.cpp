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
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100;

string res[] = {"NOT BICOLORABLE", "BICOLORABLE"};

class Graph {
public:
	vector<int> dist;
	vector<vector<pair<int, int> > > L;
	vector<bool> visited;

	Graph(int n) {
		init(n);
	}

	void init(int n) {
		dist = vector<int>(n, 0);
		L = vector<vector<pair<int, int> > >(n);
		visited = vector<bool>(n, false);
	}

	void addEdge(int a, int b, int c, bool undirected) {
		L[a].push_back(pii(b, c));
		if (undirected)
			L[b].push_back(pii(a, c));
	}

	bool isBipartite() {
		bool bipartite = true;
		queue<int> q;
		dist[0] = 0;
		for (q.push(0); !q.empty() && bipartite; q.pop()) {
			int index = q.front();
			for (int i = 0; i < SIZE(L[index]); ++i) {
				int next = L[index][i].first;
				if (!visited[next]) {
					dist[next] = 1 - dist[index];
					visited[next] = true;
					q.push(next);
				} else if (dist[next] == dist[index]) {
					bipartite = false;
					break;
				}
			}
		}
		return bipartite;
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int n; cin >> n && n;) {
		Graph graph(n);
		int m; cin >> m;
		for (int i = 0; i < m; ++i) {
			int a, b; cin >> a >> b;
			graph.addEdge(a, b, 0, true);
		}
		cout << res[graph.isBipartite()] << "." << endl;
	}
	return 0;
}
