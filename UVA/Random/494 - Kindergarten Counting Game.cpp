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
#define SZ(a) ((int)a.size())
#define FOR(i, s, e) for (int i = s; i < e; ++i)
#define REP(i, e) for (int i = 0; i < e; ++i)
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(c) c.begin(), c.end()
#define EPSILON 1e-6

int solve(string str)
{
	for (int i = 0; i < str.size(); ++i)
		if (!isalpha(str[i])) str[i] = ' ';
	int res = 0;
	stringstream sin(str);
	for (string s; sin >> s; ++res);
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (string str; getline(cin, str);)
		printf("%d\n", solve(str));
	return 0;
}