#include <iostream>
#include <cstdio>
using namespace std;

bool vis[501];

int main() {
	bool ok = true;
	for (int i = 0; i < 501; i += 2, ok = !ok) {
		vis[i] = vis[i + 1] = ok;
	}
	for (int n, m; scanf("%d%d", &m, &n) && (m && n);) {
		int res = 0;
		if (n == 1 || m == 1) {
			res = max(n, m);
		} else if (n == 2 || m == 2) {
			for (int i = 0; i < max(2, max(n, m)); ++i)
				if (vis[i]) res += 2;
		} else if (m >= 3 || n >= 3) {
			res = ((m * n) >> 1) + int((m * n) % 2);
		}
		printf("%d knights may be placed on a %d row %d column board.\n", res, m, n);
	}
	return 0;
}
