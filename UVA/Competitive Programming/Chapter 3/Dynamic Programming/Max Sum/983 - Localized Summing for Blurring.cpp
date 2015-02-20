#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

typedef long long int64;

 int const MAX = 1000 + 5;

 int matrix[MAX][MAX];

int main() {
	for (int n, m, x = 0; scanf("%d%d", &n, &m) != EOF; ++x) {
		if (x > 0) puts("");
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf("%d", &matrix[i][j]);
				if (i > 0) matrix[i][j] += matrix[i - 1][j];
				if (j > 0) matrix[i][j] += matrix[i][j - 1];
				if (i > 0 && j > 0)
					matrix[i][j] -= matrix[i - 1][j - 1];
			}
		int64 total = 0;
		for (int i = 0; i + m <= n; ++i)
			for (int j = 0; j + m <= n; ++j) {
				int c = i + m - 1;
				int d = j + m - 1;
				int cur = matrix[c][d];
				if (i > 0) cur -= matrix[i - 1][d];
				if (j > 0) cur -= matrix[c][j - 1];
				if (i > 0 && j > 0)
					cur += matrix[i - 1][j - 1];
				total += (int64) cur;
				printf("%d\n", cur);
			}
		printf("%ld\n", total);
	}
	return 0;
}