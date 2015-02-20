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
#include <fstream>
using namespace std;

const int MAXN = 100000010;

bool prime[MAXN];

inline static void fillPrime() {
	memset(prime, true, sizeof prime);
	for (int i = 3; i << 1 < MAXN; i += 2)
		if (prime[i]) {
			for (int j = i << 1; j < MAXN; j += i)
				prime[j] = false;
		}
}

inline static bool isPrime(const int n) {
	if (n < 2 || n % 2 == 0) return false;
	return prime[n];
}

int main(int argc, char **args) {
	fillPrime();
	for (int n; scanf("%d", &n) != EOF; ) {
		printf("%d ", n);
		if (n & 1) {
			if (isPrime(n - 2))
				printf("is the sum of 2 and %d.", n - 2);
			else
				printf("is not the sum of two primes!");
		} else {
			const int s = (n >> 1) - 1;
			bool found = false;
			for (int i = s; i >= 1 && !found; --i)
				if (isPrime(i) && isPrime(n - i)) {
					printf("is the sum of %d and %d.", i, n - i);
					found = true;
				}
			if (!found) printf("is not the sum of two primes!");
		}
		printf("\n");
	}
	return 0;
}