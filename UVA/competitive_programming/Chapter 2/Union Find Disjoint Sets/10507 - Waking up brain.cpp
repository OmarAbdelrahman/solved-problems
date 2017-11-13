#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <set>
#include <queue>
using namespace std;

#define f(x) (x - 'A')
#define t(x) (char)(x + 'A')
#define foreach(i, c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
int const MAX = 26;

int awake[MAX];
set<int> L[MAX];

int solve(int nawake) {
	queue<pair<int, int> > brain;
	int res = 0, depth = res;
	for (int i = 0; i < MAX; i++)
		if (awake[i] == 3)
			brain.push(make_pair(i, 0));
	for (; !brain.empty(); brain.pop(), ++res) {
		int node = brain.front().first;
		depth = brain.front().second;
		foreach(nextNode, L[node])
			if (++awake[*nextNode] == 3)
				brain.push(make_pair(*nextNode, depth + 1));
	}
	return res == nawake ? depth : -1;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int nslept, edges; cin >> nslept >> edges;) {
		string conn; cin >> conn;
		fill(awake, awake + MAX, 0);
		for (int i = 0; i < MAX; i++)
			L[i].clear();
		foreach(node, conn) awake[f(*node)] = 3;
		for (int i = 0; i < edges; i++) {
			string s; cin >> s;
			int a = f(s[0]), b = f(s[1]);
			L[a].insert(b);
			L[b].insert(a);
		}
		int res = solve(nslept);
		if (res > -1)
			printf("WAKE UP IN, %d, YEARS\n", res);
		else
			printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}

