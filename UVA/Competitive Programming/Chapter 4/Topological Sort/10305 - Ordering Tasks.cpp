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
int const MAX = 100 + 1;

class TopSort {
public:
	vector<vector<pair<int, int> > > L;
	vector<int> num;
	vector<int> topSort;

	TopSort(int n) {
		topSort.clear();
		L = vector<vector<pair<int, int> > >(n);
		num = vector<int>(n, -1);
	}

	void add(int a, int b, int c = 0) {
		L[a].push_back(make_pair(b, c));
	}

	void getTopSort() {
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
	for (int n, m; cin >> n >> m;) {
		if (n + m == 0) break;
		TopSort graph(n);
		for (int i = 0; i < m; ++i) {
			int a, b; cin >> a >> b;
			graph.add(a - 1, b - 1);
		}
		graph.getTopSort();
		cout << graph.topSort[0] + 1;
		for (int i = 1; i < SIZE(graph.topSort); ++i)
			cout << " " << graph.topSort[i] + 1;
		cout << endl;
	}
	return 0;
}
