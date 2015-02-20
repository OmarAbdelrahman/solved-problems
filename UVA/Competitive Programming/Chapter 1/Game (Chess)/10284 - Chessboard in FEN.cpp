#include <cstdio>
#include <string>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

#define LENGTH(a) ((int)a.length())
#define abs(x) (x < 0 ? -x : x)
#define ok(x, y) x >= 0 && x < 8 && y >= 0 && y < 8

char grid[8][8];
bool fady[8][8];

void move(int x, int y, int dx, int dy) {
	fady[x][y] = false;
	for (int step = 1; step < 8; ++step) {
		int xx = step * dx + x, yy = step * dy + y;
		if (ok(xx, yy)) {
			if (grid[xx][yy] == '.')
				fady[xx][yy] = false;
			else
				break;
		} else {
			continue;
		}
		fady[xx][yy] = false;
	}
}

void doAskary(char ch, int x, int y) {
	fady[x][y] = false;
	if (ch == 'p') {
		if (ok(x + 1, y - 1) && grid[x + 1][y - 1] == '.') fady[x + 1][y - 1] = false;
		if (ok(x + 1, y + 1) && grid[x + 1][y + 1] == '.') fady[x + 1][y + 1] = false;
	}
	if (ch == 'P') {
		if (ok(x - 1, y - 1) && grid[x - 1][y - 1] == '.') fady[x - 1][y - 1] = false;
		if (ok(x - 1, y + 1) && grid[x - 1][y + 1] == '.') fady[x - 1][y + 1] = false;
	}
}

void doRook(int x, int y) {
	move(x, y, -1, 0);
	move(x, y, +1, 0);
	move(x, y, 0, +1);
	move(x, y, 0, -1);
}

void doFeel(int x, int y) {
	move(x, y, -1, -1);
	move(x, y, +1, +1);
	move(x, y, -1, +1);
	move(x, y, +1, -1);
}

void doQueen(int x, int y) {
	doRook(x, y);
	doFeel(x, y);
}

void doKnight(int x, int y) {
	fady[x][y] = false;
	for (int dx = -2; dx <= 2; ++dx)
		for (int dy = -2; dy <= 2; ++dy)
			if (abs(dx * dy) == 2) {
				int xx = dx + x, yy = dy + y;
				if (ok(xx, yy) && grid[xx][yy] == '.')
					fady[xx][yy] = false;
			}
}

void doKing(int x, int y) {
	fady[x][y] = false;
	int move[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
	for (int i = 0; i < 8; ++i) {
		int xx = x + move[i][0], yy = y + move[i][1];
		if (ok(xx, yy) && grid[xx][yy] == '.')
			fady[xx][yy] = false;
	}
}

int main() {
	for (string s, ss; cin >> s;) {
		for (int i = 0; i < LENGTH(s); ++i)
			if (s[i] == '/') s[i] = ' ';
		memset(fady, true, sizeof(fady));
		stringstream sin(s);
		for (int row = 0; sin >> ss; ++row) {
			int posIndx = -1;
			for (int i = 0; i < LENGTH(ss); ++i)
				if (isdigit(ss[i])) {
					if (posIndx == -1) posIndx = i;
					for (int j = i; j < i + (ss[i] - '0'); ++j)
						grid[row][posIndx++] = '.';
				} else {
					if (posIndx == -1) posIndx = i;
					grid[row][posIndx++] = ss[i];
				}
		}
		for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j)
			switch (grid[i][j]) {
				case 'p':
				case 'P':
					doAskary(grid[i][j], i, j);
					break;
				case 'r':
				case 'R':
					doRook(i, j);
					break;
				case 'n':
				case 'N':
					doKnight(i, j);
					break;
				case 'b':
				case 'B':
					doFeel(i, j);
					break;
				case 'q':
				case 'Q':
					doQueen(i, j);
					break;
				case 'k':
				case 'K':
					doKing(i, j);
					break;
				default: break;
			}
		int res = 0;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				res += (int)fady[i][j];
		printf("%d\n", res);
	}
	return 0;
}