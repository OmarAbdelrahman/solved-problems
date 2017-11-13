#include <iostream>
#include <cstdio>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

bool equal(int a[][3], int b[][3]) {
	REP(i, 3) REP(j, 3)
		if (a[i][j] != b[i][j]) return false;
	return true;
}

int main() {
	int zeros[3][3];
	REP(i, 3) REP(j, 3) zeros[i][j] = 0;
	int c; cin >> c;
	while (c--) {
		int mat[3][3], now[3][3];
		REP(i, 3) REP(j, 3) {
			char ch; cin >> ch;
			mat[i][j] = now[i][j] = ch - '0';
		}
		int cnt = -1;
		while (true) {
			if (equal(zeros, mat)) break;
			REP(i, 3) REP(j, 3) {
				int s = 0;
				for (int dx = -1; dx <= 1; ++dx)
					for (int dy = -1; dy <= 1; ++dy)
						if ((dx == 0) ^ (dy == 0)) {
							int x = i + dx, y = j + dy;
							if (x >= 0 && x < 3 && y >= 0 && y < 3)
								s += mat[x][y];
						}
				now[i][j] = s % 2;
			}
			REP(i, 3) REP(j, 3) mat[i][j] = now[i][j];
			++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
