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

#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define f(x) (x - 'A')
#define t(x) (char)(x + 'A')

int val[256];
vector<int> L[26];
bool visited[26];

void dfs(int monster, int hero, int step, int MOD) {
	step = (step + 1) % MOD;
	if (step == 0)
		visited[monster] = true;
	FOREACH(node, L[monster]) {
		int carven = *node;
		if (!visited[carven] && carven != hero) {
			if (visited[monster]) cout << t(monster) << " ";
			dfs(carven, monster, step, MOD);
			return;
		}
	}
	cout << "/" << t(monster) << endl;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (string scenario; cin >> scenario && scenario != "#";) {
		char monster; cin >> monster;
		char hero; cin >> hero;
		int k; cin >> k;
		fill(visited, visited + 26, false);
		for (int i = 0; i < 26; i++)
			L[i].clear();
		for (int i = 0; i < LENGTH(scenario); i++)
			if (scenario[i] == ';' || scenario[i] == '.')
				scenario[i] = ' ';
		stringstream sin(scenario);
		for (string conn; sin >> conn;) {
			int a = f(conn[0]);
			for (int i = 2; i < LENGTH(conn); i++)
				L[a].push_back(f(conn[i]));
		}
		dfs(f(monster), f(hero), 0, k);
	}
	return 0;
}
