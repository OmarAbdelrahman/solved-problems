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

int const MAX = 3000 + 1;
int A[MAX][MAX];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int v, e; scanf("%d%d", &v, &e);
		memset(A, 0, sizeof(A));
		for (int i = 0, a, b; i < e; ++i) {
			scanf("%d%d", &a, &b);
			A[a - 1][b - 1] = 1;
			A[b - 1][a - 1] = 1;
		}
		int koko = 0;
		for (int i = 0; i < v; ++i)
			for (int j = i + 1; j < v; ++j)
				if (A[i][j])
					for (int k = j + 1; k < v; ++k)
						if (A[j][k] && A[k][i])
							++koko;
		printf("%d\n", koko);
	}
	return 0;
}