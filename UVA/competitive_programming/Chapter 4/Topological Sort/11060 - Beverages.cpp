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
#define LENGTH(s) ((int)s.length())
#define SIZE(s) ((int)s.size())
int const MAX = 100 + 2;

map<string, int> ID;
string drink[MAX];

class TopSort {
public:
	vector<vector<pair<int, int> > > L;
	vector<int> indegree;
	vector<int> topSort;
	vector<int> num;

	TopSort(int n) {
		indegree = vector<int>(n, 0);
		topSort.clear();
		L = vector<vector<pair<int, int> > >(n);
		num = vector<int>(n, -1);
	}

	void add(int a, int b, int c = 0) {
		L[a].push_back(make_pair(b, c));
		++indegree[b];
	}

	bool bfsTopSort() {
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 0; i < SIZE(indegree); ++i)
			if (indegree[i] == 0)
				q.push(i);
		for (; !q.empty();) {
			int node = q.top();
			q.pop();
			topSort.push_back(node);
			for (int i = 0; i < SIZE(L[node]); ++i) {
				int next = L[node][i].first;
				--indegree[next];
				L[node].erase(L[node].begin() + i--);
				if (indegree[next] == 0)
					q.push(next);
			}
		}
		return noEdges();
	}

	bool noEdges() {
		bool ok = true;
		for (int i = 0; i < SIZE(L) && ok; ++i)
			if (!L[i].empty())
				ok = false;
		return ok;
	}

	void dfsTopSort() {
		for (int i = 0; i < SIZE(L); ++i)
			if (num[i] == -1)
				dfs(i);
		reverse(topSort.begin(), topSort.end());
	}

	void dfs(int u) {
		num[u] = 0;
		for (int i = 0; i < SIZE(L[u]); ++i) {
			pair<int, int> v = L[u][i];
			if (num[v.first] == -1)
				dfs(v.first);
		}
		topSort.push_back(u);
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int n, c = 1; cin >> n; ++c) {
		int index = 0;
		for (int i = 0; i < n; ++i) {
			cin >> drink[i];
			ID[drink[i]] = index++;
		}
		TopSort graph(n);
		int m; cin >> m;
		for (int i = 0; i < m; ++i) {
			string a, b; cin >> a >> b;
			graph.add(ID[a], ID[b]);
		}
		if (graph.bfsTopSort()) {
			printf("Case #%d: Dilbert should drink beverages in this order:", c);
			for (int i = 0; i < SIZE(graph.topSort); ++i)
				cout << " " << drink[graph.topSort[i]];
		}
		puts(".\n");
	}
	return 0;
}
