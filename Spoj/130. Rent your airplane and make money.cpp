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

struct order {
	order() {}
	order(int s, int d, int p)
		: start(s), duration(d), price(p) {}
	bool operator < (const order& o) const {
		return start < o.start;
	}
	int start, duration, price;
};

int cache[10001];
order orders[10001];

static inline void get_max(int& a, int b) {
	if (b > a) a = b;
}

static int next_index(int low, int value, int n) {
	int high = n - 1;
	int result = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (orders[mid].start >= value) {
			high = mid - 1;
			result = mid;
		} else
			low = mid + 1;
	}
	return result;
}

static int solve(int index, int n) {
	if (index >= n)
		return 0;
	if (cache[index] > -1)
		return cache[index];
	cache[index] = solve(index + 1, n);
	get_max(cache[index], solve(next_index(index + 1, orders[index].start + orders[index].duration, n), n) + orders[index].price);
	return cache[index];
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d", &orders[i].start, &orders[i].duration, &orders[i].price);
		sort(orders, orders + n);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(0, n));
	}
	return 0;
}