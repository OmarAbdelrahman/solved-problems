#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

int start_row[9];
int row[9], res;

inline void get_min(int& a, int b) {
	if (b < a) a = b;
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
			s += start_row[i] != row[i];
		get_min(res, s);
	} else for (int cur_row = 1; cur_row < 9; ++cur_row) {
		if (place(col, cur_row)) {
			row[col] = cur_row;
			solve(col + 1);
		}
	}
}

int main() {
	for (int c = 1, i; scanf("%d", &start_row[1]) != EOF; ++c) {
		memset(row, 0, sizeof(row));
		for (i = 2; i < 9; ++i)
			scanf("%d", &start_row[i]);
		res = 0x3f3f3f3f;
		solve(1);
		printf("Case %d: %d\n", c, res);
	}
	return 0;
}