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

template<class T> inline void getMax(T& a, T b) {
	if (a < b) a = b;
}

int main() {
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	cin >> totalTime >> categories;
	for (int i = 0; i < categories; ++i) 
		cin >> points[i] >> minutes[i];
	for (int i = 0; i < categories; ++i)
		for (int j = 0; j <= totalTime; ++j)
			if (j - minutes[i] >= 0) 
				getMax(memo[j], memo[j - minutes[i]] + points[i]);
	cout << memo[t] << endl;
	return 0;
}