 /*
ID: 1010
PROG: range
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>lude <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <limits.h>
#include <map>
#include <math.h>
#include <set>
using namespace std;

#define MAX 251

int res[MAX];

inline void output() {
	for (int i = 2; i < MAX; ++i)
		if (res[i]) cout << i << " " << res[i] << endl;
}

void solve(int G[MAX][MAX], int size) {
	int dp[MAX][MAX];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= size; ++i)
		for (int j = 1; j <= size; ++j) {
			if (G[i][j]) 
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			for (int k = 2; k <= dp[i][j]; ++k)
				++res[k];
		}
	output();
}

int main() {
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	int size; cin >> size;
	vector<string> grid(size + 1);
	int G[MAX][MAX];
	memset(G, 0, sizeof(G));
	for (int i = 1; i <= size; ++i) {
		cin >> grid[i];
		for (int j = 0; j < grid[i].size(); ++j)
			G[i][j + 1] = (int)(grid[i][j] == '1');
	}
	solve(G, size);
	return 0;
}