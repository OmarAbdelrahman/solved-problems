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
int const MAX = 67;

struct io {
	template<class T> inline static T next() {
		T n; std::cin >> n;
		return n;
	}
};

int64 memo[MAX][MAX][2];

int64 solve(int n, int s, int locked) {
	if (n == 0 && s == 0)
		return memo[n][s][locked] = 1;
	if (n < 0 || s < 0 || s > n)
		return 0;
	if (memo[n][s][locked] != -1)
		return memo[n][s][locked];
	return memo[n][s][locked] = solve(n - 1, s, 0) + solve(n - 1, s - locked, 1);
}

int main(int argc, char **args) {
	memset(memo, -1, sizeof memo);
	while (true) {
		int n = io::next<int>();
		int s = io::next<int>();
		if (n < 0 && s < 0)
			break;
		printf("%lld\n", solve(n, s, 1));
	}
	return 0;
}