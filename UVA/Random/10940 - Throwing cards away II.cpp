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
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int64;
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define FOR(i, s, e) for (int i = s; i < e; ++i)
#define REP(i, e) for (int i = 0; i < e; ++i)
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(c) c.begin(), c.end()
#define MAX 1006
#define EPS 1e-9
#define PI acos(-1.0)
#define isPowerOfTwo(x) ((x & (x - 1)) == 0)

int arr[500005];

int main() {
	int x = 2;
	arr[1] = 1;
	for (int i = 1; i < 500001; ++i) {
		if (isPowerOfTwo(i)) {
			arr[i] = i;
			x = 2;
		} else {
			arr[i] = x;
			x += 2;
		}
	}
	for (int n; scanf("%d", &n) && n;) {
		printf("%d\n", arr[n]);
	}
	return 0;
}
