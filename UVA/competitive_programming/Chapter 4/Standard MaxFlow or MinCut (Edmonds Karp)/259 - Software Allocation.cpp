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
int const MAXC = 10;
int const MAXA = 26;
int const INF = 1 << 29;

vector<vector<int> > cap;
vector<int> flow;
vector<int> parent;

void initNetwork(int n) {
	cap = vector<vector<int> >(n, vector<int>(n, 0));
}

void addEdge(int a, int b, int c) {
	cap[a][b] = c;
}

void getPath(int src) {
	parent = flow = vector<int>(cap.size());
	vector<bool> vis(cap.size(), false);
	flow[src] = INF;
	int cur = src;
	while (cur != -1) {
		int next = -1;
		int m = 0;
		vis[cur] = true;
		for (int i = 0; i < SIZE(cap); i++) {
			if (flow[i] < min(flow[cur], cap[cur][i])) {
				flow[i] = min(flow[cur], cap[cur][i]);
				parent[i] = cur;
			}
			if (flow[i] > m && !vis[i]) {
				next = i;
				m = flow[i];
			}
		}
		cur = next;
	}
}

int maxFlow(int src, int trg) {
	if (src == trg) return INF;
	int totalFlow = 0;
	while (true) {
		getPath(src);
		if (!flow[trg]) break;
		for (int cur = trg; cur != src; cur = parent[cur]) {
			cap[parent[cur]][cur] -= flow[trg];
			cap[cur][parent[cur]] += flow[trg];
		}
		totalFlow += flow[trg];
	}
	return totalFlow;
}

int main(int argc, char **argv) {
	for (string s; getline(cin, s);) {
		vector<string> data;
		data.push_back(s);
		while (getline(cin, s) && s != "")
			data.push_back(s);
		initNetwork(MAXA + MAXC + 2);
		int totalUsers = 0;
		for (int i = 0; i < SIZE(data); ++i) {
			int application = data[i][0] - 'A';
			int users = data[i][1] - '0';
			totalUsers += users;
			addEdge(MAXA + MAXC, application, users);
			for (int j = 3; j < LENGTH(data[i]) - 1; ++j)
				addEdge(application, (data[i][j] - '0') + MAXA, 1);
		}
		for (int i = 0; i < MAXC; ++i)
			addEdge(i + MAXA, MAXA + MAXC + 1, 1);
		int flow = maxFlow(MAXA + MAXC, MAXA + MAXC + 1);
		if (flow == totalUsers) {
			string res(MAXC, '_');
			for (int i = 0; i < MAXC; ++i)
				for (int app = 0; app < MAXA; ++app)
					if (cap[i + MAXA][app] == 1) {
						res[i] = (char)(app + 'A');
						break;
					}
			cout << res << endl;
		} else
			puts("!");
	}
	return 0;
}
