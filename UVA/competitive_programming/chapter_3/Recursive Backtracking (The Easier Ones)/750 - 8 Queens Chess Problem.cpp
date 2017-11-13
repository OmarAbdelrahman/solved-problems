#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

int r, c;
int row[9];
int solution;

bool place(int col, int cur_row) {
	for (int pos = 1; pos < col; ++pos)
		if (row[pos] == cur_row || (abs(cur_row - row[pos]) == abs(pos - col)))
			return false;
	return true;
}

void solve(int col) {
	int cur_row, j;
	if (col == 9) {
		printf("%2d      %d", ++solution, row[1]);
		for (j = 2; j < 9; ++j) printf(" %d", row[j]);
		puts("");
	} else for (cur_row = 1; cur_row < 9; ++cur_row) {
		if (col == c && cur_row != r)
			continue;
		if (place(col, cur_row)) {
			row[col] = cur_row;
			solve(col + 1);
		}
	}
}

int main() {
	int TC; scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &r, &c);
		solution = 0;
		memset(row, 0, sizeof(row));
		puts("SOLN       COLUMN");
		puts(" #      1 2 3 4 5 6 7 8\n");
		solve(1);
		if (TC) puts("");
	}
	return 0;
}