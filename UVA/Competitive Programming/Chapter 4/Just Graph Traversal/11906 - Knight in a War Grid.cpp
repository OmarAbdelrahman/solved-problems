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

int const MAX = 105;

int n, m, kn, km;
bool visited[MAX][MAX];
bool water[MAX][MAX];
int matrix[MAX][MAX];

bool ok(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(int x, int y, int knight[][2], int size) {
	if (visited[x][y])
		return;
	visited[x][y] = true;
	for (int i = 0; i < size; ++i) {
		int nx = x + knight[i][0];
		int ny = y + knight[i][1];
		if (ok(nx, ny) && !water[nx][ny])
			matrix[x][y]++;
	}
	for (int i = 0; i < size; ++i) {
		int nx = x + knight[i][0];
		int ny = y + knight[i][1];
		if (ok(nx, ny))
			solve(nx, ny, knight, size);
	}
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	for (int K = 1; TC-- > 0; ++K) {
		scanf("%d%d%d%d", &n, &m, &kn, &km);
		int q, a, b; scanf("%d", &q);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				water[i][j] = visited[i][j] = false;
				matrix[i][j] = 0;
			}
		while (q-- > 0) {
			scanf("%d%d", &a, &b);
			visited[a][b] = water[a][b] = true;
		}
		int knight[8][2] = {{-kn, -km}, {-kn, km}, {kn, -km}, {km, kn}, {-km, kn}, {km, -kn}, {kn, km}, {-km, -kn}};
		if (kn == km) {
			solve(0, 0, knight, 4);
		} else if (kn == 0) {
			int king[4][2] = {{-km, 0}, {km, 0}, {0, km}, {0, -km}};
			solve(0, 0, king, 4);
		} else if (km == 0) {
			int king[4][2] = {{-kn, 0}, {kn, 0}, {0, kn}, {0, -kn}};
			solve(0, 0, king, 4);
		} else {
			solve(0, 0, knight, 8);
		}
		int odd = 0;
		int even = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (matrix[i][j] > 0 || (i == 0 && j == 0)) {
					if (matrix[i][j] & 1) odd++; else even++;
				}
		printf("Case %d: %d %d\n", K, even, odd);
	}
	return 0;
}