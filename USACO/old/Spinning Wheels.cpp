/*
ID: 1010
PROG: spin
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
#include <limits.h>
using namespace std;

#define MAX 5
int const MOD = 360;
int const INF = 0x3f3f3f3f;

int S[MAX], L[MAX];
pair<int, int> wed[MAX][MAX];
bool hole[MAX][MOD];

inline bool all(int i) {
	return hole[0][i] == hole[1][i] &&
		   hole[1][i] == hole[2][i] &&
		   hole[2][i] == hole[3][i] &&
		   hole[3][i] == hole[4][i];
}

bool ok() {
	for (int i = 0; i < MOD; i++)
		if (all(i) && hole[0][i]) return true;
	return false;
}

int _main() {
	for (int i = 0; i < MAX; i++) {
		cin >> S[i] >> L[i];
		for (int j = 0; j < L[i]; j++)
			cin >> wed[i][j].first >> wed[i][j].second;
	}
	for (int t = 0; t < MOD; t++) {
		memset(hole, false, sizeof(hole));
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < L[i]; j++) {
				for (int k = wed[i][j].first; k <= wed[i][j].first + wed[i][j].second; k++)
					hole[i][k % MOD] = true;
				(wed[i][j].first += S[i]) %= MOD;
			}
		if (ok()) return t;
	}
	return -1;
}

int main() {
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
	int res = _main();
	if (res == -1) 
		cout << "none" << endl;
	else 
		cout << res << endl;
	return 0;
}