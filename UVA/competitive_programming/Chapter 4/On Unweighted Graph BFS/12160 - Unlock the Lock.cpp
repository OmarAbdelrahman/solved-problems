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

int const MAXB = 12;
int const MAXL = 10000;
int const MODULO = 10000;

int button[MAXB];
bool visited[MAXL];

struct state {
	int value, cost;
	state() {}
	state(int v, int c)
		: value(v), cost(c) {}
};

int solve(int src, int trg, int n) {
	memset(visited, false, sizeof(visited));
	queue<state> q;
	visited[src] = true;
	for (q.push(state(src, 0)); !q.empty(); q.pop()) {
		int value = q.front().value;
		int cost = q.front().cost;
		if (value == trg)
			return cost;
		for (int i = 0; i < n; ++i) {
			int next = value + button[i];
			if (next >= MODULO)
				next -= MODULO;
			if (!visited[next]) {
				q.push(state(next, cost + 1));
				visited[next] = true;
			}
		}
	}
	return -1;
}

int main(int argc, char **args) {
	for (int lock, unlock, buttons, K = 1; cin >> lock >> unlock >> buttons; ++K) {
		if (lock + unlock + buttons == 0)
			break;
		for (int i = 0; i < buttons; ++i)
			scanf("%d", &button[i]);
		printf("Case %d: ", K);
		int result = solve(lock, unlock, buttons);
		if (result == -1)
			puts("Permanently Locked");
		else
			printf("%d\n", result);
	}
	return 0;
}