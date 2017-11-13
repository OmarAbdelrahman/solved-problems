#include <cstdio>
#include <string.h>
using namespace std;

int count_bit(int n) {
	return n == 0 ? 0 : count_bit(n & (n - 1)) + 1;
}

void get_min(int& a, int b) {
	if (a > b) a = b;
}

int main() {
	int code[105];
	bool vis[1 << 15];
	int TC; scanf("%d", &TC);
	for (int i, j, m; TC--;) {
		int P; scanf("%d", &P);
		int N; scanf("%d", &N);
		for (i = 0; i < N; ++i) {
			code[i] = 0;
			for (j = 0; j < P; ++j) {
				int c; scanf("%d", &c);
				if (c) code[i] |= 1 << j;
			}
		}
		int res = 0x3f3f3f3f;
		for (m = 0; m < 1 << P; ++m) {
			memset(vis, false, sizeof(vis));
			bool ok = true;
			for (i = 0; i < N; ++i) {
				if (vis[m & code[i]]) {
					ok = false;
					break;
				}
				vis[m & code[i]] = true;
			}
			if (ok) get_min(res, count_bit(m));
		}
		printf("%d\n", res);
	}
	return 0;
}