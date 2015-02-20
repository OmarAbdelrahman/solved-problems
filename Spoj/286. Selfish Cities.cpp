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

int const MAXN = 202;
int const BIG_NUM = 1 << 29;

int N, cost[MAXN][MAXN];
int X[MAXN], Y[MAXN];
int Lx[MAXN], Ly[MAXN];
int parent[MAXN], Q[MAXN];

int maxw_bipartite() {
	int tail, s, k;
	memset(Ly, 0, sizeof(int) * N);
	for (int i = 0; i < N; i++)
		Lx[i] = *max_element(cost[i], cost[i] + N);
	memset(X, -1, sizeof(int) * N);
	memset(Y, -1, sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		int head;
		memset(parent, -1, sizeof(int) * N);
		for (Q[0] = i, head = 0, tail = 1; head < tail && X[i] < 0; head++) {
			s = Q[head];
			for (int j = 0; j < N; j++) {
				if (X[i] >= 0) break;
				if (Lx[s] + Ly[j] > cost[s][j] || parent[j] >= 0)
					continue;
				Q[tail++] = Y[j];
				parent[j] = s;
				if (Y[j] < 0)
					while (j >= 0) {
						s = parent[j]; Y[j] = s; k = X[s]; X[s] = j; j = k;
					}
			}
		}
		if (X[i] < 0 && i-- + (k = BIG_NUM)) {
			for (int head = 0; head < tail; head++)
				for (int j = 0; j < N; j++)
					if (parent[j] == -1)
						k = min(k, Lx[Q[head]] + Ly[j] - cost[Q[head]][j]);
			for (int j = 0; j < tail; j++)
				Lx[Q[j]] -= k;
			for (int j = 0; j < N; j++)
				if (parent[j] >= 0)
					Ly[j] += k;
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		if (X[i] >= 0)
			sum += cost[i][X[i]];
	return sum;
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		int c1; scanf("%d", &c1);
		int c2; scanf("%d", &c2);
		N = c1 + c2;
		memset(cost, 0, sizeof(cost));
		for (int a, b, c; scanf("%d%d%d", &a, &b, &c);) {
			if (a == 0 && b == 0 && c == 0)
				break;
			cost[a - 1][b - 1] = c;
		}
		printf("%d\n", maxw_bipartite());
	}
	return 0;
}