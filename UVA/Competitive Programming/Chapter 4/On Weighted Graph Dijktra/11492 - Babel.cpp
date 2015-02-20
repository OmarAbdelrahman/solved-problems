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

int const MAXW = 2000;
int const BIG_NUM = INT_MAX;

struct state {
	int index;
	int cost;
	char ch;
	state() {}
	state(int i, int c, char C)
		: index(i), cost(c), ch(C) {}
	bool operator < (const state &s) const {
		return cost > s.cost;
	}
};

inline void add(string s, int &ID, map<string, int> &m, vector<vector<state> > &graph) {
	if (m.find(s) == m.end()) {
		graph.push_back(vector<state>());
		m[s] = ID++;
	}
}

int f(char &ch) {
	if (ch == '#') return 0; else return ch - 'a' + 1;
}

int solve(int &start, int &trg, const vector<vector<state> > &graph) {
	vector<vector<int> > distance(graph.size(), vector<int>(28, BIG_NUM));
	vector<vector<bool> > visited(graph.size(), vector<bool>(28, false));
	for (int alpha = 0; alpha < visited[0].size(); ++alpha) {
		distance[start][alpha] = 0;
		visited[start][alpha] = false;
	}
	priority_queue<state> q;
	for (q.push(state(start, 0, '#')); !q.empty();) {
		int index = q.top().index;
		int cost = q.top().cost;
		char ch = q.top().ch;
		q.pop();
		if (index == trg)
			return cost;
		if (visited[index][f(ch)])
			continue;
		visited[index][f(ch)] = true;
		for (int i = 0; i < graph[index].size(); ++i) {
			state next = graph[index][i];
			int newc = cost + next.cost;
			if (newc < distance[next.index][f(next.ch)] && ch != next.ch) {
				distance[next.index][f(next.ch)] = newc;
				q.push(state(next.index, newc, next.ch));
			}
		}
	}
	return BIG_NUM;
}

int main(int argc, char **args) {
	for (int words; scanf("%d", &words) && words > 0;) {
		map<string, int> value;
		int ID = 0;
		vector<vector<state> > graph;
		string src; cin >> src;
		add(src, ID, value, graph);
		string trg; cin >> trg;
		add(trg, ID, value, graph);
		for (int i = 0; i < words; ++i) {
			string a, b, c; cin >> a >> b >> c;
			add(a, ID, value, graph);
			add(b, ID, value, graph);
			int u = value[a];
			int v = value[b];
			int cost = c.length();
			graph[u].push_back(state(v, cost, c[0]));
			graph[v].push_back(state(u, cost, c[0]));
		}
		int result = solve(value[src], value[trg], graph);
		if (result >= BIG_NUM)
			puts("impossivel");
		else
			printf("%d\n", result);
	}
	return 0;
}