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
#define MAX 256

pair<string, int> solve(string str)
{
	int value[MAX];
	memset(value, 0, sizeof(value));
	for (int i = 0; i < str.size(); ++i)
		if (isalpha(str[i])) ++value[str[i]];
	int big = -1;
	for (int i = 0; i < MAX; ++i)
		big = max(big, value[i]);
	string res;
	for (int i = 'A'; i <= 'Z'; ++i)
		if (value[i] == big) res += char(i);
	for (int i = 'a'; i <= 'z'; ++i)
		if (value[i] == big) res += char(i);
	return make_pair(res, big);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (string str; getline(cin, str);)
	{
		pair<string, int> res = solve(str);
		printf("%s %d\n", res.first.c_str(), res.second);
	}
	return 0;
}