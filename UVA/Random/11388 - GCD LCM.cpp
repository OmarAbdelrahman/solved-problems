/*
ID: 1010
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <queue>
#include <string.h>
#include <iomanip>
using namespace std;

typedef long long _int;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while (T--) {
		int G, L; scanf("%d%d", &G, &L);
		if (L % G) printf("-1\n");
		else printf("%d %d\n", G, L);
	}
	return 0;
}