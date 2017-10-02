/*
ID: 1010
PROG: checker
LANG: C++
*/

#include <cstdio>
using namespace std;

int n, cnt = 0;
int c[15];
bool R[15], LD[30];
bool RD[30];

inline void solve(int level) {
	if (level == n) {
		if (cnt < 3) {
			printf("%d", c[0] + 1);
			for (int i = 1; i < n; ++i)
				printf(" %d", c[i] + 1);
			printf("\n");
		}
		++cnt; return;
	}
	for (int i = 0; i < n; ++i)
		if (!R[i] && !LD[i - level + n] && !RD[i + level]) {
			R[i] = LD[i - level + n] = RD[i + level] = 1;
			c[level] = i;
			solve(level + 1);
			R[i] = LD[i - level + n] = RD[i + level] = 0;
		}
}

int main() {
	freopen("checker.in", "r", stdin);
	freopen("checker.out", "w", stdout);
	scanf("%d", &n);
	solve(0);
	printf("%d\n", cnt);
	return 0;
}