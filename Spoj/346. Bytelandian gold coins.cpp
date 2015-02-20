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

typedef long long i64;

map<int, i64> cache;

static i64 solve(int n) {
	if (n <= 10)
		return n;
	if (cache.find(n) != cache.end())
		return cache[n];
	return cache[n] = max((i64) n, solve(n / 2) + solve(n / 3) + solve(n / 4));
}

int main(int argc, char **args) {
	for (int n; scanf("%d", &n) != EOF;)
		cout << solve(n) << endl;
	return 0;
}