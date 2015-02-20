#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

const int oo = 0x3f3f3f3f;
const double eps = 1e-12;
typedef vector<vector<int> > AdjacentMatrix;
typedef vector<vector<pair<int, int> > > AdjacentList;

int r, c;
char board[150][150];
bool visited[150][150];
const int moves[6][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1} };

struct state_t {
	state_t(int _x, int _y)
		: x(_x), y(_y) {}
	state_t() {}
	int x, y;
};

inline bool ok(int _r, int _c) {
	return _r >= 0 && _c >= 0 && _r < r && _c < c;
}

inline bool Adjacent(int& tx, int& ty) {
	for (int i = 0; i < 5; i++) {
		int x = tx + moves[i][0], xx = tx + moves[i + 1][0];
		int y = ty + moves[i][1], yy = ty + moves[i + 1][1];
		if (ok(x, y) && ok(xx, yy)) if (board[x][y] == '*' && board[x][y] == board[xx][yy])
			return true;
	}
	if (ok(tx + moves[0][0], ty) && ok(tx, ty + moves[5][1]))
		if (board[tx + moves[0][0]][ty] == '*' && board[tx + moves[0][0]][ty] == board[tx][ty + moves[5][1]])
			return true;
	return false;
}

inline void MarkBlocked(int& tx, int& ty) {
	queue <state_t> q;
	q.push(state_t(tx, ty));
	board[tx][ty] = 'B';
	while (!q.empty()) {
		state_t current = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int x = current.x + moves[i][0];
			int y = current.y + moves[i][1];
			if (ok(x, y) && (board[x][y] == '*' || board[x][y] == '(' || board[x][y] == ')' || board[x][y] == 'I')) {
				board[x][y] = 'B';
				q.push(state_t(x, y));
			}
		}
	}
}

inline void MarkDirections(int& tx, int& ty) {
	board[tx][ty] = '(';
	queue<state_t> q;
	q.push(state_t(tx, ty));
	while (!q.empty()) {
		state_t current = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int x = current.x + moves[i][0];
			int y = current.y + moves[i][1];
			if (ok(x, y)) {
				if (board[x][y] == '*') {
					if (board[current.x][current.y] == '(')
						board[x][y] = ')';
					else if (board[current.x][current.y] == ')')
						board[x][y] = '(';
					q.push(state_t(x, y));
				} else if (board[x][y] == '(' && board[current.x][current.y] == '(') {
					MarkBlocked(current.x, current.y);
				} else if (board[x][y] == ')' && board[current.x][current.y] == ')') {
					MarkBlocked(current.x, current.y);
				}
			}
		}
	}
}

inline void MakeBoard(queue<state_t>& q) {
	while (!q.empty()) {
		state_t current = q.front(); q.pop();
		if (board[current.x][current.y] != 'I')
			continue;
		if (Adjacent(current.x, current.y))
			MarkBlocked(current.x, current.y);
		else
			MarkDirections(current.x, current.y);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
#endif
	while (scanf("%d%d", &r, &c) != EOF && (r && c)) {
		queue<state_t> q;
		for (int i = 0; i < r; i++) scanf("%s", board[i]);
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
			if (board[i][j] == 'I') q.push(state_t(i, j));
		MakeBoard(q);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				(board[i][j] == '*' || board[i][j] == 'I') ? printf("%1c", 'F') : printf("%1c", board[i][j]);
			printf("\n");
		}
	}
	return 0;
}
