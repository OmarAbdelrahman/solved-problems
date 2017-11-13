#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 9

int size, res, A[MAX];
int grid[MAX][MAX];

inline void get_min(int& a, int b) {
	if (a > b) a = b;
}

int main() {
	int TC; scanf("%d", &TC);
	for (int i, j, min; TC--;) {
		scanf("%d", &size);
		for (i = 0; i < size; ++i) {
			A[i] = i;
			for (j = 0; j < size; ++j)
				scanf("%d", &grid[i][j]);
		}
		res = 0x3f3f3f3f;
		do {
			min = 0;
			for (i = 0; i < size; ++i)
				min += grid[i][A[i]];
			get_min(res, min);
		} while (next_permutation(A, A + size));
		printf("%d\n", res);
	}
	return 0;
}