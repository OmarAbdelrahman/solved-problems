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

bool prime[] = {1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0};
bool vis[20];
int circle[20], n;

void printCircle(int depth) {
	if (depth == n) {
		printf("%d", circle[0]);
		for (int i = 1; i < n; ++i)
			printf(" %d", circle[i]);
		puts("");
	} else for (int i = 2; i <= n; ++i)
		if (!vis[i]) {
			if (depth == n - 1 && !prime[1 + i])
				continue;
			if (!prime[circle[depth - 1] + i])
				continue;
			vis[i] = true;
			circle[depth] = i;
			printCircle(depth + 1);
			circle[depth] = 0;
			vis[i] = false;
		}
}

int main() {
	circle[0] = 1;
	for (int c = 0; scanf("%d", &n) != EOF; ++c) {
		if (c) puts("");
		memset(vis, false, sizeof(vis));
		printf("Case %d:\n", c + 1);
		printCircle(1);
	}
	return 0;
}