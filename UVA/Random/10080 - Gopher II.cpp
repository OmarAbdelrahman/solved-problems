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

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
int const oo = 1 << 29;

struct node {
    int to;
    int rIndex;
    int flow;
    node() : to(0), rIndex(0), flow(0) {}
    node(int t, int r, int f)
        : to(t), rIndex(r), flow(f) {}
};

typedef vector<vector<node> > adjList;

adjList adj;
vector<bool> vis;

void init(int n) {
    adj.clear();
    adj.resize(n);
    vis.clear();
    vis.resize(n, false);
}

void addEdge(int from, int to, int flow) {
    node n1 = node(to, adj[to].size(), flow);
    node n2 = node(from, adj[from].size(), 0);
    adj[to].push_back(n2);
    adj[from].push_back(n1);
}

int hatPathYaSebres(int src, int sink, int flow) {
    if (vis[src] || flow == 0)
        return 0;
    vis[src] = true;
    if (src == sink) return flow;
    for (int i = 0; i < (int) adj[src].size(); ++i) {
        int j = adj[src][i].to;
        int nf = min(flow, adj[src][i].flow);
        int rf = hatPathYaSebres(j, sink, nf);
        if (rf > 0) {
            int rev = adj[src][i].rIndex;
            adj[src][i].flow -= rf;
            adj[j][rev].flow += rf;
            return rf;
        }
    }
    return 0;
}

int maxFlow(int src, int sink) {
    int tf = 0, flow;
    if (src == sink) return oo;
    while ((flow = hatPathYaSebres(src, sink, oo))) {
        vis = vector<bool>(adj.size(), false);
        tf += flow;
    }
    return tf;
}

// src n + m
// trg n + m + 1

int main(int argc, char **argv) {
	for (int n, m, second, velocity; cin >> n >> m >> second >> velocity;) {
		vector<pair<double, double> > gopher(n);
		vector<pair<double, double> > hole(m);
		init(n + m + 2);
		for (int i = 0; i < n; ++i) {
			cin >> gopher[i].first >> gopher[i].second;
			addEdge(n + m, i, 1);
		}
		for (int i = 0; i < m; ++i) {
			cin >> hole[i].first >> hole[i].second;
			addEdge(i + n, n + m + 1, 1);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				double dist1 = hypot(gopher[i].first - hole[j].first, gopher[i].second - hole[j].second);
				double dist2 = (velocity * 1.0) * (second * 1.0);
				if (dist1 < dist2)
					addEdge(i, j + n, 1);
			}
		cout << n - maxFlow(n + m, n + m + 1) << endl;
	}
    return 0;
}
