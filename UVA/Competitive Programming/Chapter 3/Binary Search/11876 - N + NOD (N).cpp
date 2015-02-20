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

int const MAX_SEQ = 64726;
int const LARGE = 1000000 + 1;

int seq[MAX_SEQ];
int res[LARGE];

int numDiv(int n) {
	int cnt = 0;
	for (int i = 1; i * i <= n; ++i)
		if (n % i == 0) {
			cnt += 2;
			if (n / i == i)
				--cnt;
		}
	return cnt;
}

int main() {
	seq[0] = 0; seq[1] = 1; seq[2] = 2;
	for (int i = 3; i < MAX_SEQ; ++i)
		seq[i] = seq[i - 1] + numDiv(seq[i - 1]);
	res[0] = 0; res[1] = 1;
	for (int i = 2; i < LARGE; ++i)
		res[i] = res[i - 1] + binary_search(seq, seq + MAX_SEQ, i);
	int cases; scanf("%d", &cases);
	for (int c = 1; cases-- != 0; ++c) {
		int A, B; scanf("%d%d", &A, &B);
		printf("Case %d: %d\n", c, res[B] - res[A - 1]);
	}
	return 0;
}