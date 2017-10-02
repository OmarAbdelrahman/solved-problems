/*
ID: 1010
PROG: humble
LANG: C++
*/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <numeric>
#include <utility>
#include <limits.h>
using namespace std;

typedef long long _int;
#define maxIndex 100001
#define maxPrime 101

int n, k, turn;
_int prime[maxPrime];
_int humble[maxIndex];
int primeMultiple[maxPrime];

template<class T> inline void getMin(T& a, T b) {
	if (b < a) a = b;
}

int main() {
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	scanf("%d%d", &k, &n);
	for (int a = 0; a < k; ++a) 
		scanf("%d", &prime[a]);
	humble[turn = 0, turn++] = 1;
	while (turn <= n) {
		_int small = LLONG_MAX;
		for (int a = 0; a < k; ++a) 
			getMin(small, prime[a] * humble[primeMultiple[a]]);
		for (int a = 0; a < k; ++a) 
			if (prime[a] * humble[primeMultiple[a]] == small) 
				primeMultiple[a]++;
		humble[turn++] = small;
	}
	cout << humble[n] << endl;
	return 0;
}