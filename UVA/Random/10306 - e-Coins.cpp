#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int table[500][500];
int types, states;
int cValue[50], itValue[50];

int solve(int x, int y) {
	if (x == 0 && y == 0) {
		return 0;
	}
	int& value = table[x][y];
	if (value != -1)
		return value;
	value = INT_MAX - 1000;
	for (int index = 0; index < types; ++index) {
		int xx = x - cValue[index];
		int yy = y - itValue[index];
		if (xx >= 0 && yy >= 0)
			value = min(value, solve(xx, yy) + 1);
	}
	return value;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int nCases;
	scanf("%d", &nCases);
	while (nCases--) {
		scanf("%d%d", &types, &states);
		memset(table, -1, sizeof table);
		for (int index = 0; index < types; ++index)
			scanf("%d%d", &cValue[index], &itValue[index]);
		int small = INT_MAX - 1000;
		for (int one = 0; one <= states; ++one)
			for (int two = 0; two <= states; ++two)
				if (one * one + two * two == states * states)
					small = min(small, solve(one, two));
		if (small == INT_MAX - 1000) {
			puts("not possible");
		} else {
			printf("%d\n", small);
		}
	}
	return 0;
}