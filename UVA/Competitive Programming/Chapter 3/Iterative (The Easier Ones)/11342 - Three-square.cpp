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

struct triplet {
	int x, y, z;
	triplet()
		: x(-1), y(-1), z(-1) {}
	triplet(int _x, int _y, int _z)
		: x(_x), y(_y), z(_z) {}
};

int main() {
	int const MAX = 50000 + 1;
	triplet koko[MAX];
	for (int a = 0; a * a < MAX; ++a)
		for (int b = a; b * b < MAX; ++b)
			for (int c = b; c * c < MAX; ++c) {
				int n = (a * a) + (b * b) + (c * c);
				if (n < MAX && koko[n].x == -1) {
					koko[n] = triplet(a, b, c);
				}
			}
	int cases; scanf("%d", &cases);
	while (cases-- != 0) {
		int n; scanf("%d", &n);
		if (koko[n].x == -1)
			printf("-1\n");
		else
			printf("%d %d %d\n", koko[n].x, koko[n].y, koko[n].z);
	}
	return 0;
}