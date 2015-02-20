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

int const MAXK = 16;
int const MAXS = 1200;
int const MAXI = 196;
typedef long long i64;
i64 const INF = 2079324314 + 1000000;

vector<int> prime;
i64 memo[MAXI][MAXK][MAXS];

template<class T> static vector<T> generat_primes(T n) {
	T i, j;
	vector<T> primes(1, 2);
	for (i = 3; i <= n; i += 2) {
		for (j = 0; primes[j] * primes[j] <= i; j++) {
			if (!(i % primes[j])) break;
		}
		if (primes[j] * primes[j] > i)
			primes.push_back(i);
	}
	return primes;
}

i64 solve(int index, int k, int sum) {
	if (index >= MAXI || k < 0 || sum < 0)
		return 0;
	if (k == 0)
		return sum == 0;
	if (memo[index][k][sum] != -1)
		return memo[index][k][sum];
	i64 result = 0;
	result = solve(index + 1, k - 1, sum - prime[index]) + solve(index + 1, k, sum);
	return memo[index][k][sum] = result;
}

int main(int argc, char **argv) {
	prime = generat_primes<int>(MAXS);
	for (int n, k; scanf("%d%d", &n, &k);) {
		if (n == 0 && k == 0)
			break;
		memset(memo, -1, sizeof(memo));
		cout << solve(0, k, n) << endl;
	}
	return 0;
}