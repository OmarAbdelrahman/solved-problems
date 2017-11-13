#include <cstdio>
using namespace std;

#define MAX 16

int G[MAX];
char s[MAX];
int n, res;

void solve(int depth, int row, int rd, int ld) {
	if (depth == n) ++res;
	else {
		int can = row & (rd >> depth) & (ld >> (n - depth - 1)) & G[depth], pos;
		while (can) {
			pos = can & (-can);
			solve(depth + 1, pos ^ row, (pos << depth) ^ rd, (pos << (n - depth - 1)) ^ ld);
			can ^= pos;
		}
	}
}

int main() {
	for (int c = 1, i, j; scanf("%d", &n) && n; ++c, res = 0) {
		int ones1 = (1 << n) - 1;
		for (i = 0; i < n; ++i) {
			scanf("%s", s);
			G[i] = ones1;
			for (j = 0; j < n; ++j)
				if (s[j] == '*')
					G[i] &= ~(1 << j);
		}
		int ones2 = (1 << (2 * n - 1)) - 1;
		solve(0, ones1, ones2, ones2);
		printf("Case %d: %d\n", c, res);
	}
	return 0;
}