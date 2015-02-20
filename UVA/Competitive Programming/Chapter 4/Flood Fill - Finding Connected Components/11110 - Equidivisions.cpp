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
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100 + 5;

int grid[MAX][MAX];
bool visited[MAX][MAX];
bool taken[MAX];

void fill(int x, int y, int num, int size) {
	if (visited[x][y]) return;
	visited[x][y] = true;
	for (int dx = -1; dx <= 1; ++dx)
		for (int dy = -1; dy <= 1; ++dy)
			if ((dx == 0) ^ (dy == 0)) {
				int nx = x + dx;
				int ny = y + dy;
				if (nx >= 0 && nx < size && ny >= 0 && ny < size)
					if (!visited[nx][ny] && grid[nx][ny] == num)
						fill(nx, ny, num, size);
			}
}

template<class T> void print(int n, int m, T a[][MAX]) {
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < m; ++j)
			cout << a[i][j] << " ";
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int n; cin >> n && n != 0;) {
		fill(grid[0], grid[n + 3], 0);
		fill(visited[0], visited[n + 3], false);
		fill(taken, taken + MAX, false);
		cin.ignore();
		for (int i = 0; i < n - 1; ++i) {
			string s; getline(cin, s);
			stringstream sin(s);
			for (int a, b; sin >> a >> b;)
				grid[a - 1][b - 1] = i + 1;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (!visited[i][j] && !taken[grid[i][j]]) {
					taken[grid[i][j]] = true;
					fill(i, j, grid[i][j], n);
				}
		bool ok = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ok &= visited[i][j];
		ok ? puts("good") : puts("wrong");
	}
	return 0;
}
