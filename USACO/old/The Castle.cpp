/*
ID: 1010
PROG: castle
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<string.h>
#include<map>
using namespace std;

#define wsz 4
#define sz(a) ((int)a.size())

struct module_t {
	module_t() {
		memset(wall, false, sizeof wall);
	}
	int value;
	bool wall[wsz];
};

int n, m;
int const W = 0, N = 1;
int const E = 2, S = 3;
bool vis[51][51];
vector<vector<module_t> > board;

bool in(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void count(int x, int y, int& cnt, int v) {
	if (vis[x][y] || !in(x, y))
		return;
	vis[x][y] = true;
	++cnt, board[x][y].value = v;
	if (!board[x][y].wall[N])
		count(x - 1, y, cnt, v);
	if (!board[x][y].wall[S])
		count(x + 1, y, cnt, v);
	if (!board[x][y].wall[E])
		count(x, y + 1, cnt, v);
	if (!board[x][y].wall[W])
		count(x, y - 1, cnt, v);
}

int main() {
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
	scanf("%d%d", &m, &n);
	board = vector<vector<module_t> >(n, vector<module_t>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("%d", &board[i][j].value);
			if (board[i][j].value >= 8) {
				board[i][j].value -= 8;
				board[i][j].wall[S] = true;
			}
			if (board[i][j].value >= 4) {
				board[i][j].value -= 4;
				board[i][j].wall[E] = true;
			}
			if (board[i][j].value >= 2) {
				board[i][j].value -= 2;
				board[i][j].wall[N] = true;
			}
			if (board[i][j].value >= 1) {
				board[i][j].value -= 1;
				board[i][j].wall[W] = true;
			}
		}
	int rooms = 0, big = -1, v = 0;
	map<int, int> size;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!vis[i][j]) {
				int counter = 0;
				++rooms, count(i, j, counter, ++v);
				big = max(big, counter);
				size[rooms] = counter;
			}
	char direction = 'E';
	int biggest = -1, x = 0, y = 0;
	for (int j = 0; j < m; ++j)
		for (int i = n - 1; i >= 0; --i) {
			if (i > 0 && board[i][j].value != board[i - 1][j].value) {
				int sum = size[board[i][j].value] + size[board[i - 1][j].value];
				if (sum > biggest) {
					biggest = sum;
					x = i + 1, y = j + 1;
					direction = 'N';
				}
			}
			if (j + 1 < m && board[i][j].value != board[i][j + 1].value) {
				int sum = size[board[i][j].value] + size[board[i][j + 1].value];
				if (sum > biggest) {
					biggest = sum;
					x = i + 1, y = j + 1;
					direction = 'E';
				}
			}
		}
	printf("%d\n%d\n%d\n%d %d %c\n", rooms, big, biggest, x, y, direction);
	return 0;
}
