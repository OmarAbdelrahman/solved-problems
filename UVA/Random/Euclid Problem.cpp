#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

#define eps                           (1e-12)
#define _lim                          10000
#define All(A)                        A.begin(), A.end()
#define foreach(i, c)                 for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

const int oo = 0x3f3f3f3f;
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;

long gcd(long p, long q, long *x, long *y) {
	long x1, y1, g;
	if (q > p) return gcd(q, p, y, x);
	if (!q) {
		*x = 1, *y = 0;
		return p;
	}
	g = gcd(q, p % q, &x1, &y1);
	*x = y1, *y = (x1 - floor((double)p / (double)q) * (double)y1);
	return g;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
#endif
	long a, b, x, y;
	while (cin >> a >> b) {
		long ans = gcd(a, b, &x, &y);
		cout << x << ' ' << y << ' ' << ans << endl;
	}
	return 0;
}