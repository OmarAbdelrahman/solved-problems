/*
ID: 1010
PROG: ttwo
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define maxT 10
#define sz(a) ((int)a.size())

char board[maxT][maxT];
pair<int, int> start[2];
int dir[2];
bool vis[maxT][maxT][4][maxT][maxT][4];

inline bool ok(int x, int y) {
	return x >= 0 && y >= 0 && x < maxT && y < maxT && board[x][y] != '*';
}

void nextMove(int n) {
	int x, y;
	switch (dir[n]) {
	case 0:
		x = start[n].first - 1;
		y = start[n].second;
		break;
	case 1:
		x = start[n].first;
		y = start[n].second + 1;
		break;
	case 2:
		x = start[n].first + 1;
		y = start[n].second;
		break;
	case 3:
		x = start[n].first;
		y = start[n].second - 1;
		break;
	}
	if (ok(x, y)) {
		start[n] = make_pair(x, y);
	} else {
		++dir[n];
		dir[n] %= 4;
	}
}

int solve() {
	int ans = 0;
	while (true) {
		nextMove(0);
		nextMove(1);
		++ans;
		if (start[0] == start[1])
			return ans;
		if (vis[start[1].first][start[1].second][dir[1]][start[0].first][start[0].second][dir[0]])
			return 0;
		vis[start[1].first][start[1].second][dir[1]][start[0].first][start[0].second][dir[0]] = true;
	}
}

int main() {
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	for (int i = 0; i < maxT; ++i)
		for (int j = 0; j < maxT; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'F')
				start[0] = make_pair(i, j);
			if (board[i][j] == 'C')
				start[1] = make_pair(i, j);
		}
	dir[0] = dir[1] = 0;
	cout << solve() << endl;
	return 0;
}