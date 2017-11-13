#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

#define MAX 50000

int I[MAX], R[MAX];

inline void get_max(int &a, int b) {
	if (a < b) a = b;
}

int main() {
	int TC = 0, i, n, LNIS, *it;
	while (true) {
		for (n = 0; scanf("%d", &I[n]) && I[n] != -1; ++n);
		if (I[0] == -1) break;
		R[0] = I[0], LNIS = 1;
		for (i = 1; i < n; ++i) {
			it = upper_bound(R, R + LNIS, I[i], greater<int>());
			get_max(LNIS, (int) (it - R) + 1);
			*it = I[i];
		}
		if (TC) puts("");
		printf("Test #%d:\n", ++TC);
		printf("  maximum possible interceptions: %d\n", LNIS);
	}
	return 0;
}