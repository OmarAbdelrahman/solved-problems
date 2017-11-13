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
int const INF = 1 << 29;

struct node {
    node() : to(0), rIndex(0), flow(0) {}
    node(int t, int r, int f)
        : to(t), rIndex(r), flow(f) {}
	int to, rIndex, flow;
};

vector<vector<node> > cap;
vector<bool> vis;

void initNetwork(int n) {
    cap.clear(), cap.resize(n);
    vis.clear(), vis.resize(n, false);
}

void addEdge(int from, int to, int flow) {
    node n1 = node(to, cap[to].size(), flow);
    node n2 = node(from, cap[from].size(), 0);
    cap[to].push_back(n2);
    cap[from].push_back(n1);
}

int hatPathYaSebres(int src, int trg, int flow) {
    if (vis[src] || flow == 0)
        return 0;
    vis[src] = true;
    if (src == trg) return flow;
    for (int i = 0; i < SIZE(cap[src]); ++i) {
        int j = cap[src][i].to;
        int newFlow = min(flow, cap[src][i].flow);
        int resFlow = hatPathYaSebres(j, trg, newFlow);
        if (resFlow > 0) {
            int rev = cap[src][i].rIndex;
            cap[src][i].flow -= resFlow;
            cap[j][rev].flow += resFlow;
            return resFlow;
        }
    }
    return 0;
}

int maxFlow(int src, int trg) {
    int totalFlow = 0, flow;
    if (src == trg) return INF;
    while ((flow = hatPathYaSebres(src, trg, INF))) {
        vis = vector<bool>(cap.size(), false);
        totalFlow += flow;
    }
    return totalFlow;
}

int main(int argc, char **argv) {
	for (int c = 1, nodes; cin >> nodes && nodes; ++c) {
		initNetwork(nodes);
		int src; cin >> src;
		int trg; cin >> trg;
		int edges; cin >> edges;
		for (int i = 0; i < edges; ++i) {
			int a, b, c; cin >> a >> b >> c;
			addEdge(a - 1, b - 1, c);
			addEdge(b - 1, a - 1, c);
		}
		printf("Network %d\nThe bandwidth is %d.\n", c, maxFlow(src - 1, trg - 1));
		puts("");
	}
    return 0;
}
