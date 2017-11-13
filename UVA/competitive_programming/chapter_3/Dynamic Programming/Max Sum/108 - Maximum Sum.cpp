#include <cstdio>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

inline void get_max(int &a, int b) {
	if (b > a) a = b;
}

int main() {
	int n, M[101][101]; scanf("%d", &n);
	REP(i, n) REP(j, n) {
		scanf("%d", &M[i][j]);
		if (i) M[i][j] += M[i - 1][j];
		if (j) M[i][j] += M[i][j - 1];
		if (i && j) M[i][j] -= M[i - 1][j - 1];
	}
	int res = -(1 << 30), cur;
	REP(a, n) REP(b, n)
		for (int c = a; c < n; c++)
			for (int d = b; d < n; d++) {
				cur = M[c][d];
				if (a) cur -= M[a - 1][d];
				if (b) cur -= M[c][b - 1];
				if (a && b) cur += M[a - 1][b - 1];
				get_max(res, cur);
			}
	printf("%d\n", res);
	return 0;
}