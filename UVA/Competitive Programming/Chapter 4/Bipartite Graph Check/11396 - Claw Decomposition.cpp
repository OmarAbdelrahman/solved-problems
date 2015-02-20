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

typedef long long ll;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100;

string res[] = { "NO", "YES" };

class Graph {
public:
	vector<int> color;
	vector<vector<pair<int, int> > > L;
	vector<bool> visited;

	Graph(int n) { init(n); }

	void init(int n) {
		color = vector<int>(n, 2);
		L = vector<vector<pair<int, int> > >(n);
		visited = vector<bool>(n, false);
	}

	void addEdge(int a, int b, int c = 0) {
		L[a].push_back(pii(b, c));
		L[b].push_back(pii(a, c));
	}

	bool isBipartite(int s = 0) {
		queue<int> q;
		color[s] = 1;
		visited[s] = true;
		for (q.push(s); !q.empty(); q.pop()) {
			int index = q.front();
			for (int i = 0; i < SIZE(L[index]); ++i) {
				int next = L[index][i].first;
				if (!visited[next]) {
					visited[next] = true;
					color[next] = 1 - color[index];
					q.push(next);
				} else if (color[next] == color[index])
					return false;
			}
		}
		return true;
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int nodes; cin >> nodes && nodes;) {
		Graph graph(nodes);
		for (int a, b; cin >> a >> b && (a != 0 && b != 0);)
			graph.addEdge(a - 1, b - 1);
		cout << res[graph.isBipartite()] << endl;
	}
	return 0;
}
