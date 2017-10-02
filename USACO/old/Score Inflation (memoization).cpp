/*
ID: 1010
PROG: inflate
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
using namespace std;

typedef long long _int;
#define MAX 10000 + 2

int totalTime, categories;
int points[MAX];
int minutes[MAX];
_int memo[MAX];

template<class T> inline void getMax(T& a,T b) {
	if (a < b) a = b;
}

_int solve(int rem) {
	if (rem < 0) return 0;
	_int& ret = memo[rem];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < categories; ++i)
		if (rem - minutes[i] >= 0) 
			getMax(ret, solve(rem - minutes[i]) + points[i]);
	return ret;
}

int main() {
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	cin >> totalTime >> categories;
	for (int i = 0; i < categories; ++i) 
		cin >> points[i] >> minutes[i];
	cout << solve(totalTime) << endl;
	return 0;
}