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

int const MAXN = 550;
int const SMALL_NUM = 1 << 31;

int high = SMALL_NUM;
int matrix[MAXN][MAXN];
bool visited[MAXN];

int solve(int index, int n) {
	if (visited[index])
		return 0;
	visited[index] = true;
	int count = 1;
	for (int i = 0; i < n; ++i)
		if (matrix[index][i] == high)
			count += solve(i, n);
	return count;
}

int main(int argc, char **args) {
	for (int n, e, i, a, b, c, result; scanf("%d%d", &n, &e); high = SMALL_NUM) {
		if (n == 0 && e == 0)
			break;
		memset(visited, false, sizeof(visited));
		for (i = 0; i < n; ++i)
			fill(matrix[i], matrix[i] + n, SMALL_NUM);
		for (i = 0; i < e; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			high = max(high, c);
			matrix[a - 1][b - 1] = max(matrix[a - 1][b - 1], c);
			matrix[b - 1][a - 1] = matrix[a - 1][b - 1];
		}
		result = solve(0, n);
		for (i = 1; i < n; ++i) {
			memset(visited, false, sizeof(visited));
			result = max(result, solve(i, n));
		}
		printf("%d\n", result);
	}
	return 0;
}