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

int const MAXN = 105;
int const BIG_NUM = 0x3f3f3f3f;

int A, B;
int G[MAXN][MAXN * 2];
int dist[MAXN][MAXN * 2];
bool visited[MAXN][MAXN * 2];

struct state {
	state() {}
	state(int _i, int _c, int _k)
		: i(_i), c(_c), k(_k) {}
	bool operator < (const state &s) const {
		return c > s.c;
	}
	int i, c, k;
};

int solve(int src, int trg, int L, int K) {
	int size = src + 1;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			dist[i][j] = BIG_NUM;
	dist[src][0] = 0;
	priority_queue<state> q;
	for (q.push(state(src, 0, 0)); !q.empty();) {
		int index = q.top().i;
		int cost = q.top().c;
		int k = q.top().k;
		q.pop();
		if (index == trg)
			return cost;
		if (visited[index][k])
			continue;
		visited[index][k] = true;
		for (int next = 1; next < size; ++next) {
			if (cost + G[index][next] < dist[next][k]) {
				dist[next][k] = cost + G[index][next];
				q.push(state(next, cost + G[index][next], k));
			}
			if (G[index][next] <= L && k < K) {
				if (dist[next][k + 1] > dist[index][k]) {
					dist[next][k + 1] = dist[index][k];
					q.push(state(next, cost, k + 1));
				}
			}
		}
	}
	int result = BIG_NUM;
	for (int k = 0; k <= K; ++k)
		result = min(result, dist[trg][k]);
	return result;
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	for (int L, K, M; TC-- > 0;) {
		scanf("%d%d%d%d%d", &A, &B, &M, &L, &K);
		int size = A + B;
		for (int i = 0; i <= size; ++i)
			for (int j = 0; j <= size; ++j)
				if (i == j) G[i][j] = 0; else G[i][j] = BIG_NUM;
		while (M-- > 0) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			G[a][b] = G[b][a] = c;
		}
		for (int k = 1; k <= A; ++k)
			for (int i = 1; i <= size; ++i)
				for (int j = 1; j <= size; ++j)
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
		printf("%d\n", solve(A + B, 1, L, K));
	}
	return 0;
}