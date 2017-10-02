/*
ID: 1010
PROG: numtri
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define sz(a) ((int)a.size())

int main() {
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	int h;
	vector<vector<int> > b;
	scanf("%d", &h); b.resize(h);
	for (int i = 0; i < h; ++i)
		for (int j = 0; j <= i; ++j) {
			int t; scanf("%d", &t);
			b[i].push_back(t);
		}
	int big = b[0][0];
	for (int i = 1; i < h; ++i)
		for (int j = 0; j < sz(b[i]); ++j) {
			if (i == j)
				b[i][j] += b[i - 1][j - 1];
			else if (j == 0)
				b[i][j] += b[i - 1][j];
			else
				b[i][j] += max(b[i - 1][j - 1], b[i - 1][j]);
			big = max(big, b[i][j]);
		}
	printf("%d\n", big);
	return 0;
}