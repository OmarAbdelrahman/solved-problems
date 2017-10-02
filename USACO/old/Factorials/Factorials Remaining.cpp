/*
ID: 1010
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <assert.h>
using namespace std;

#define MAX 4221

int n;
int const MODULO = 10;
int remaining[MAX];

vector<int> generate(int size) {
	int i, j;
	vector<int> primes(1, 2);
	for (i = 3; i <= size; i += 2) {
		for (j = 0; primes[j] * primes[j] <= i; ++j)
			if (i % primes[j] == 0)
				break;
		if (primes[j] * primes[j] > i)
			primes.push_back(i);
	}
	return primes;
}

int get(int x, int p) {
	int r = 0;
	while (x) {
		r += x / p;
		x /= p;
	}
	return r;
}

int main() {
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	scanf("%d", &n);
	vector<int> primes = generate(n);
	for (int i = 0; i < primes.size(); ++i)
		remaining[primes[i]] += get(n, primes[i]);
	int small = min(remaining[2], remaining[5]), res = 1;
	remaining[2] -= small, remaining[5] -= small;
	for (int i = 0; i < primes.size(); ++i)
		while (remaining[primes[i]]--) {
			res *= primes[i];
			res %= MODULO;
		}
	printf("%d\n", res);
	return 0;
}