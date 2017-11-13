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

struct Graph {
	vector<vector<int> > L;
	vector<vector<int> > T;
	vector<int> topSort;
	vector<int> component;
	vector<bool> visited;
	int compCnt;

	Graph(int n) { init(n); }

	void init(int n) {
		L = vector<vector<int> >(n);
		T = vector<vector<int> >(n);
		topSort.clear();
		component = vector<int>(n, 0);
		visited = vector<bool>(n, false);
		compCnt = 0;
	}

	void add(int a, int b) {
		L[a].push_back(b);
		T[b].push_back(a);
	}

	void doTopSort() {
		for (int i = 0; i < SIZE(L); i++)
			if (!visited[i])
				dfs(i);
		reverse(topSort.begin(), topSort.end());
	}

	void dfs(int u) {
		visited[u] = true;
		for (int i = 0; i < SIZE(L[u]); i++)
			if (!visited[L[u][i]])
				dfs(L[u][i]);
		topSort.push_back(u);
	}

	void doKosaraju() {
		for (int i = 0; i < SIZE(topSort); i++)
			if (visited[topSort[i]])
				kosaraju(topSort[i], compCnt++);
	}

	void kosaraju(int u, int compID) {
		visited[u] = false;
		component[u] = compID;
		for (int i = 0; i < SIZE(T[u]); i++)
			if (visited[T[u][i]])
				kosaraju(T[u][i], compID);
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int persons, links; cin >> persons >> links;) {
		if (persons == 0 && links == 0)
			break;
		cin.ignore();
		map<string, int> val;
		int ID = 0;
		for (int i = 0; i < persons; i++) {
			string name; getline(cin, name);
			if (!val.count(name)) val[name] = ID++;
		}
		Graph graph(persons);
		for (int i = 0; i < links; i++) {
			string a; getline(cin, a);
			string b; getline(cin, b);
			graph.add(val[a], val[b]);
		}
		graph.doTopSort();
		graph.doKosaraju();
		cout << graph.compCnt << endl;
	}
	return 0;
}
