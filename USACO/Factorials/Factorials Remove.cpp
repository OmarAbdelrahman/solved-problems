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

int remove(int& x, int p) {
	int r = 0;
	while (x % p == 0) {
		++r;
		x /= p;
	}
	return r;
}

int main() {
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	scanf("%d", &n);
	int res = 1;
	int twos = 0, five = 0;
	for (int i = 2; i <= n; ++i) {
		int now = i;
		twos += remove(now, 2);
		five += remove(now, 5);
		res = (res * now) % MODULO;
	}
	for (int i = 0; i < twos - five; ++i)
		res = (res * 2) % MODULO;
	printf("%d\n", res);
	return 0;
}