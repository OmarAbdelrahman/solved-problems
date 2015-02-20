/*
ID: 1010
PROG: camelot
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <limits.h>
#include <map>
#include <math.h>
#include <set>
using namespace std;

#define MAX 31
int const INFINITE = 0x3f3f3f3f;

struct State {
	State() {}
	State(int _x, int _y)
		: x(_x), y(_y) {}
	bool operator < (const State& s) const {
		if (this->x == s.x)
			return this->y < s.y;
		return this->x < s.x;
	}
	int x, y;
};

struct Node {
	Node() {}
	Node(State _s, int _c)
		: s(_s), c(_c) {}
	State s;
	int c;
};

int row, col;
vector<State> positions;
int res[MAX][MAX];
int knightDistances[MAX][MAX][MAX][MAX];

inline bool ok(int x, int y) {
	return x >= 0 && x < row && y >= 0 && y < col;
}

inline int kingDistance(int x1, int y1, int x2, int y2) {
	return max(abs(x1 - x2), abs(y1 - y2));
}

void doKnights(int x, int y) {
	queue<Node> q;
	q.push(Node(State(x, y), 0));
	knightDistances[x][y][x][y] = 0;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int dx = -2; dx <= 2; ++dx)
			for (int dy = -2; dy <= 2; ++dy)
				if (abs(dx * dy) == 2) {
					int xx = dx + now.s.x;
					int yy = dy + now.s.y;
					if (ok(xx, yy) && knightDistances[x][y][xx][yy] == INFINITE) {
						q.push(Node(State(xx, yy), now.c + 1));
						knightDistances[x][y][xx][yy] = now.c + 1;
						knightDistances[xx][yy][x][y] = now.c + 1;
					}
				}
	}
}

int noCarryKing(int r, int c) {
	int res = 0;
	for (int knight = 1; knight < (int)positions.size(); ++knight) {
		if (knightDistances[positions[knight].x][positions[knight].y][r][c] == INFINITE)
			return INFINITE;
		res += knightDistances[positions[knight].x][positions[knight].y][r][c];
	}
	return res;
}

int solve() {
	int res = INFINITE;
	for (int r = 0; r < row; ++r) for (int c = 0; c < col; ++c) {
		int withoutKing = noCarryKing(r, c);
		if (withoutKing == INFINITE) continue;
		if (withoutKing + kingDistance(positions[0].x, positions[0].y, r, c) < res)
			res = withoutKing + kingDistance(positions[0].x, positions[0].y, r, c);
		int allDistance = withoutKing;
		for (int knight = 1; knight < (int)positions.size(); ++knight) {
			if (knightDistances[positions[knight].x][positions[knight].y][r][c] == INFINITE)
				break;
			State kingPosition = positions[0];
			int king[9][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0} };
			for (int step = 1; step <= 3; ++step) {
				for (int move = 0; move < 9; ++move) {
					int newX = kingPosition.x + king[move][0] * step;
					int newY = kingPosition.y + king[move][1] * step;
					if (ok(newX, newY)) {
						int toNewPoint = kingDistance(kingPosition.x, kingPosition.y, newX, newY);
						toNewPoint += knightDistances[positions[knight].x][positions[knight].y][newX][newY];
						toNewPoint += knightDistances[newX][newY][r][c];
						allDistance += toNewPoint - knightDistances[positions[knight].x][positions[knight].y][r][c];
						res = min(res, allDistance);
						allDistance -= toNewPoint - knightDistances[positions[knight].x][positions[knight].y][r][c];
					}
				}
			}
		}
	}
	return res;
}

int main() {
	freopen("camelot.in", "r", stdin);
	freopen("camelot.out", "w", stdout);
	cin >> row >> col;
	char c; int r;
	for (; cin >> c >> r; positions.push_back(State(r - 1, c - 'A')));
	memset(knightDistances, INFINITE, sizeof(knightDistances));
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			doKnights(i, j);
	cout << solve() << endl;
	return 0;
}
