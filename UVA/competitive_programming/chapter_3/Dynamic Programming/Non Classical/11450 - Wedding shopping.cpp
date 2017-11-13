#include <cstdio>
#include <string.h>
using namespace std;

int const oo = 0x3f3f3f3f;

int money, garment;
int memo[210][25], P[210][25];

inline void get_max(int &a, int b) {
	if (b > a) a = b;
}

int solve(int money, int G) {
	if (money < 0) return -oo;
	if (G == garment) return ::money - money;
	int &ret = memo[money][G], i;
	if (ret != -1) return ret;
	ret = -oo;
	for (i = 1; i <= P[G][0]; ++i)
		get_max(ret, solve(money - P[G][i], G + 1));
	return ret;
}

int main() {
	int TC; scanf("%d", &TC);
	for (int i, j; TC--;) {
		scanf("%d%d", &money, &garment);
		for (i = 0; i < garment; ++i) {
			scanf("%d", &P[i][0]);
			for (j = 1; j <= P[i][0]; ++j)
				scanf("%d", &P[i][j]);
		}
		memset(memo, -1, sizeof memo);
		int res = solve(money, 0);
		if (res == -oo)
			puts("no solution");
		else
			printf("%d\n", res);
	}
	return 0;
}