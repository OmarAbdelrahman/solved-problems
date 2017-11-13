#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

int board[9][9];
int row[9], res;

void get_max(int& a, int b) {
	if (b > a) a = b;
}

bool place(int col, int cur_row) {
	for (int pos = 1; pos < col; ++pos)
		if (row[pos] == cur_row || (abs(row[pos] - cur_row) == abs(pos - col)))
			return false;
	return true;
}

void solve(int col) {
	if (col == 9) {
		int s = 0, i;
		for (i = 1; i < 9; ++i)
			s += board[row[i]][i];
		get_max(res, s);
	} else for (int cur_row = 1; cur_row < 9; ++cur_row) {
		if (place(col, cur_row)) {
			row[col] = cur_row;
			solve(col + 1);
		}
	}
}

int main() {
	int TC, i, j; scanf("%d", &TC);
	while (TC--) {
		for (i = 1; i < 9; ++i)
			for (j = 1; j < 9; ++j)
				scanf("%d", &board[i][j]);
		res = -1;
		solve(1);
		printf("%5d\n", res);
	}
	return 0;
}