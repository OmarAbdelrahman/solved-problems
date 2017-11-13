#include <iostream>
#include <cstdio>
using namespace std;

inline int abs(int x) {
	return x < 0 ? -x : x;
}

int main() {
	int kases; scanf("%d", &kases);
	while (kases--) {
		int n, sz; scanf("%d%d", &n, &sz);
		for (int i = 0; i < n; ++i) {
			int a[4];
			for (int j = 0; j < 4; ++j)
				scanf("%d", &a[j]);
			int d1 = abs(a[0] - a[2]);
			int d2 = abs(a[1] - a[3]);
			if (a[0] == a[2] && a[1] == a[3]) puts("0");
			else if (d1 == d2) puts("1");
			else if (d1 % 2 == d2 % 2) puts("2");
			else puts("no move");
		}
	}
	return 0;
}
