#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 8
#define ok(x, y) (x >= 0 && x < MAX && y >= 0 && y < MAX)

bool fady[MAX][MAX];
pair<int, int> board[MAX * MAX];
int RC[MAX][MAX];
vector<int> aMoves;

void move(int x, int y, int dx, int dy) {
	fady[x][y] = false;
	for (int step = 1; step < 8; ++step) {
		int xx = step * dx + x, yy = step * dy + y;
		if (ok(xx, yy)) {
			if (!fady[xx][yy])
				break;
			else
				aMoves.push_back(RC[xx][yy]);
		}
	}
}

void makeVal(int k, bool val) {
	fady[board[k].first][board[k].second] = val;
	for (int dx = -1; dx <= 1; ++dx)
		for (int dy = -1; dy <= 1; ++dy)
			if ((dx == 0) ^ (dy == 0)) {
				int xx = board[k].first + dx;
				int yy = board[k].second + dy;
				if (ok(xx, yy))
					fady[xx][yy] = val;
			}
}

int main() {
	for (int cnt = 0; cnt < MAX * MAX; ++cnt) {
		int r = cnt / MAX, c = cnt % MAX;
		board[cnt] = make_pair(r, c);
		RC[r][c] = cnt;
	}
	for (int k, q, nQ; cin >> k >> q >> nQ;) {
		if (k == q) {
			printf("Illegal state\n");
			continue;
		}
		aMoves.clear();
		memset(fady, true, sizeof(fady));
		int x = board[q].first;
		int y = board[q].second;
		fady[board[k].first][board[k].second] = false;
		move(x, y, -1, 0);
		move(x, y, +1, 0);
		move(x, y, 0, -1);
		move(x, y, 0, +1);
		if (count(aMoves.begin(), aMoves.end(), nQ) == 0) {
			printf("Illegal move\n");
			continue;
		}
		makeVal(k, false);
		if (!fady[board[nQ].first][board[nQ].second] && count(aMoves.begin(), aMoves.end(), nQ)) {
			printf("Move not allowed\n");
			continue;
		}
		makeVal(k, true);
		aMoves.clear();
		x = board[nQ].first;
		y = board[nQ].second;
		move(x, y, -1, 0);
		move(x, y, +1, 0);
		move(x, y, 0, -1);
		move(x, y, 0, +1);
		bool ok = false;
		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy)
				if ((dx == 0) ^ (dy == 0)) {
					int xx = board[k].first + dx;
					int yy = board[k].second + dy;
					if (ok(xx, yy)) {
						if (count(aMoves.begin(), aMoves.end(), RC[xx][yy]) == 0)
							ok = true;
					}
				}
		if (ok)
			printf("Continue\n");
		else
			printf("Stop\n");
	}
	return 0;
}
