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

int const MAXC = 100000 + 2;

int location[MAXC];
int stalls, cows;

static bool ok(int diff) {
	int ncow = 1;
	int prev = 0;
	for (int now = 1; now < stalls; ++now) {
		if (location[now] - location[prev] >= diff) {
			prev = now;
			ncow++;
		}
		if (ncow == cows)
			return true;
	}
	return ncow == cows;
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%d%d", &stalls, &cows);
		int high = -1;
		for (int i = 0; i < stalls; ++i) {
			scanf("%d", &location[i]);
			high = max(high, location[i]);
		}
		sort(location, location + stalls);
		int low = 0;
		int result = 0;
		while (low <= high) {
			int mid = (low + high) >> 1;
			if (ok(mid)) {
				low = mid + 1;
				result = mid;
			} else
				high = mid - 1;
		}
		printf("%d\n", result);
	}
	return 0;
}