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

typedef long long lli;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100;
int const INF = 1000000;
#define f(x) (x - 'A')
#define t(x) (char)(x + 'A')

bool used[26];

struct Graph {
	vector<vector<int> > L;
	vector<int> num, low;
	vector<bool> visited;
	vector<int> component;
	vector<vector<int> > scc;
	int numScc, numCnt;

	Graph(int n) { init(n); }

	void init(int n) {
		L = vector<vector<int> >(n);
		num = vector<int>(n, -1);
		low = vector<int>(n, 0);
		visited = vector<bool>(n, false);
		component.clear();
		scc.clear();
		numScc = numCnt = 0;
	}

	void add(int a, int b) { L[a].push_back(b); }

	void doTarjan() {
		for (int i = 0; i < SIZE(L); i++)
			if (used[i] && num[i] == -1)
				tarjan(i);
	}

	void tarjan(int u) {
		low[u] = num[u] = numCnt++;
		visited[u] = true;
		component.push_back(u);
		for (int a = 0; a < SIZE(L[u]); a++) {
			int v = L[u][a];
			if (num[v] == -1)
				tarjan(v);
			if (visited[v])
				low[u] = min(low[u], low[v]);
		}
		if (num[u] == low[u]) {
			vector<int> cur;
			int v;
			do {
				v = component[SIZE(component) - 1];
				cur.push_back(v);
				visited[v] = false;
				component.erase(--component.end());
			} while (v != u);
			scc.push_back(cur);
		}
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	Graph graph(26);
	for (int questions, T = 0; cin >> questions && questions; T++) {
		if (T) puts("");
		fill(used, used + 26, false);
		graph.init(26);
		for (int i = 0; i < questions; i++) {
			char choices[5], answer;
			for (int j = 0; j < 5; j++) {
				cin >> choices[j];
				used[f(choices[j])] = true;
			}
			cin >> answer;
			for (int j = 0; j < 5; j++)
				graph.add(f(answer), f(choices[j]));
		}
		graph.doTarjan();
		for (int i = 0; i < SIZE(graph.scc); i++)
			sort(graph.scc[i].begin(), graph.scc[i].end());
		sort(graph.scc.begin(), graph.scc.end());
		for (int i = 0; i < SIZE(graph.scc); i++) {
			if (SIZE(graph.scc[i]) == 0)
				continue;
			cout << t(graph.scc[i][0]);
			for (int j = 1; j < SIZE(graph.scc[i]); j++)
				cout << " " << t(graph.scc[i][j]);
			cout << endl;
		}
	}
	return 0;
}
