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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

#define two(n) (1 << (n))
#define is_on(m, n) (((m) & two(n)) != 0)
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define REP(i, n) for (int i = 0; i < n; i++)
#define MAX 20000 + 5

int const oo = 1 << 30;

inline void get_max(ll &a, ll b) {
	if (a < b) a = b;
}

int main() {
	freopen("in.txt", "r", stdin);
	int TC; scanf("%d", &TC);
	ll stop[MAX];
	for (int n, c = 1; TC--; c++) {
		scanf("%d", &n);
		--n;
		REP(i, n) cin >> stop[i];
		int res = -oo, mlen = res;
		int sum = 0, s = 0, e, temp = s;
		REP(i, n) {
			sum += stop[i];
			if (sum > res) {
				res = sum;
				e = i, s = temp;
				mlen = e - s;
			}
			if (sum == res && i - temp > mlen) {
				mlen = i - temp;
				s = temp, e = i;
			}
			if (sum < 0) {
				sum = 0;
				temp = i + 1;
			}
		}
		if (res <= 0)
			printf("Route %d has no nice parts\n", c);
		else
			printf("The nicest part of route %d is between stops %d and %d\n", c, s + 1, e + 2);
	}
	return 0;
}