#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 25

int main() {
	int n, m;
	int a[MAX];
	int b[MAX];
	int c[MAX];
	int G[10], P[10];
	for (int i, j; scanf("%d%d", &n, &m) && (n || m);) {
		int res = 0;
		for (i = 0; i < n; ++i) G[i] = i;
		for (i = 0; i < m; ++i)
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		do {
			bool ok = true;
			for (i = 0; i < n; ++i)
				for (j = 0; j < n; ++j)
					if (i == G[j]) {
						P[i] = j;
						break;
					}
			for (i = 0; i < m; ++i)
				if (c[i] < 0) {
					if (abs(P[a[i]] - P[b[i]]) < -c[i]) {
						ok = false;
						break;
					}
				} else {
					if (abs(P[a[i]] - P[b[i]]) > c[i]) {
						ok = false;
						break;
					}
				}
			res += (int)ok;
		} while (next_permutation(G, G + n));
		printf("%d\n", res);
	}
	return 0;
}