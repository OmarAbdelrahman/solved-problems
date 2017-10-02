/*
ID: 1010
PROG: fence9
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

int n, m, p;

inline int gcd(int a, int b) {
	return __gcd(a, b);
}

int main() {
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);
	cin >> n >> m >> p;
	int area = p * m;
	int nm = gcd(n, m);
	int np = gcd(abs(n - p), m);
	cout << ((area - p - nm - np) / 2) + 1 << endl;
	return 0;
}
