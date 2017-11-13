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
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

typedef long long lli;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
int const MAX = 105;
int const INF = 1000000;

string grid[MAX];
int n, m;
int dx[] = {-1, 1, -1, 1, 0, 0, -1, 1};
int dy[] = {-1, -1, 1, 1, -1, 1, 0, 0};

int flood(int x, int y, char c1, char c2) {
	if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != c1)
		return 0;
	grid[x][y] = c2;
	int cnt = 1;
	for (int i = 0; i < 8; i++)
		cnt += flood(x + dx[i], y + dy[i], c1, c2);
	return cnt;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	cin.ignore();
	string line; getline(cin, line);
	while (T-- != 0) {
		for (int i = 0; getline(cin, line) && line != "";) {
			if (line[0] >= '0' && line[0] <= '9') {
				int r, c;
				sscanf(line.c_str(), "%d %d", &r, &c);
				n = i, m = LENGTH(grid[0]);
				cout << flood(r - 1, c - 1, 'W', 'w') << endl;
				flood(r - 1, c - 1, 'w', 'W');
			} else {
				grid[i++] = line;
			}
		}
		if (T) puts("");
	}
	return 0;
}
