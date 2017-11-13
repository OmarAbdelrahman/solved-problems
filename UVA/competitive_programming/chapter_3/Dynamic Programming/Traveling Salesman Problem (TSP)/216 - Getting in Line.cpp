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

int const MAX = 9;
double const OFFSET = 16.0;

double dist[MAX][MAX];
double dp[MAX][1 << MAX];
int path[MAX][1 << MAX];
int x[MAX], y[MAX];

int main() {
	for (int network = 1, computers; cin >> computers; ++network) {
		if (computers == 0)
			break;
		for (int i = 0; i < computers; ++i)
			cin >> x[i] >> y[i];
		for (int i = 0; i < computers; ++i)
			for (int j = 0; j < computers; ++j)
				dist[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
		for (int i = 0; i < MAX; ++i) {
			fill(dp[i], dp[i] + (1 << MAX), (double)INT_MAX);
			fill(path[i], path[i] + (1 << MAX), 0);
		}
		for (int i = 0; i < MAX; ++i)
			dp[i][(1 << computers) - 1] = 0.0;
		for (int mask = (1 << computers) - 2; mask >= 0; --mask) {
			for (int index = 0; index < computers; ++index)
				if (mask & (1 << index)) {
					for (int next = 0; next < computers; ++next)
						if (!(mask & (1 << next))) {
							if (dp[index][mask] > dp[next][mask | (1 << next)] + dist[index][next] + OFFSET) {
								dp[index][mask] = dp[next][mask | (1 << next)] + dist[index][next] + OFFSET;
								path[index][mask] = next;
							}
						}
				}
		}
		int start = 0;
		for (int i = 1; i < computers; ++i)
			if (dp[i][1 << i] < dp[start][1 << start])
				start = i;
		puts("**********************************************************");
		printf("Network #%d\n", network);
		int mask = 1 << start;
		int final = start;
		while (mask != (1 << computers) - 1) {
			int next = path[start][mask];
			printf("Cable requirement to connect ");
			printf("(%d,%d) to (%d,%d) is %.2lf feet.\n", x[start], y[start], x[next], y[next], dist[start][next] + OFFSET);
			mask |= (1 << next);
			start = next;
		}
		printf("Number of feet of cable required is %.2lf.\n", dp[final][1 << final]);
	}
	return 0;
}