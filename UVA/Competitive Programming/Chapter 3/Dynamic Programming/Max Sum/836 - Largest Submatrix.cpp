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
#define on(m, n) (((m) & two(n)) != 0)
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define REP(i, n) for (int i = 0; i < n; i++)
#define MAX 30

int const INF = 30 * 30;

int main() {
	int TC; scanf("%d", &TC);
	cin.ignore();
	string s; getline(cin, s);
	vector<string> board;
	int grid[MAX][MAX];
	while (TC--) {
		board.clear();
		for (; getline(cin, s) && s != ""; board.push_back(s));
		int n = SIZE(board);
		REP(i, n) REP(j, n) grid[i][j] = board[i][j] == '1' ? board[i][j] - '0' : -INF;
		REP(i, n) REP(j, n) if (j > 0) grid[i][j] += grid[i][j - 1];
		int res = -INF;
		bool uncounted = true;
		REP(left, n) for (int right = left; right < n; ++right) {
			int nmax = 0;
			REP(row, n) {
				if (left > 0)
					nmax += grid[row][right] - grid[row][left - 1];
				else
					nmax += grid[row][right];
				if (nmax < 0) nmax = 0;
				if (uncounted || nmax > res) {
					res = nmax;
					uncounted = false;
				}
			}
		}
		printf("%d\n", res);
		if (TC) cout << endl;
	}
	return 0;
}