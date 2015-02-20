#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

typedef long long i64;
const double eps = 1e-12;
const double pi = acos(-1.);
const int oo = 0x3f3f3f3f;
#define sz(A) ((int)A.size())
#define all(A) A.begin(), A.end()
typedef vector<vector<int>> AdjacentMatrix;
typedef vector<vector<pair<int, int>>> AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int n, m, value, turn, ok = 0;
AdjacentMatrix table;
vector<vector<char>> path;
deque<string> steps;
string source, target;

string toString(int x) {
	string s;
	while (x) {
		s += ((x % 10) + '0');
		x = x / 10;
	}
	reverse(all(s));
	return s;
}

int editDistance() {
	table = AdjacentMatrix(n, vector<int>(m, 0));
	path = vector<vector<char>>(n, vector<char>(m, 'n'));
	for (int i = 0; i < n; i++) {
		table[i][0] = i, path[i][0] = 'd';
	}
	for (int i = 0; i < m; i++) {
		table[0][i] = i, path[0][i] = 'i';
	}
	for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) {
		table[i][j] = table[i - 1][j - 1];
		path[i][j] = 'r';
		if (source[i - 1] != target[j - 1]) {
			table[i][j]++;
			if (table[i][j - 1] + 1 < table[i][j]) {
				table[i][j] = table[i][j - 1] + 1;
				path[i][j] = 'i';
			}
			if (table[i - 1][j] + 1 < table[i][j]) {
				table[i][j] = table[i - 1][j] + 1;
				path[i][j] = 'd';
			}
		}
	}
	return table[sz(source)][sz(target)];
}

void solve(int x, int y) {
	if (x == 0 && y == 0)
		return;
	if (path[x][y] == 'd') {
		steps.push_front(" Delete ");
		steps.front() += toString(y + 1);
		solve(x - 1, y);
	} else if (path[x][y] == 'i') {
		steps.push_front(" Insert ");
		steps.front() += toString(y);
		steps.front() += ",";
		steps.front() += target[y - 1];
		solve(x, y - 1);
	} else if (path[x][y] == 'r') {
		if (x - 1 >= 0 && y - 1 >= 0)
			if (table[x][y] == table[x - 1][y - 1]) {
				solve(x - 1, y - 1);
			} else {
				steps.push_front(" Replace ");
				steps.front() += toString(y);
				steps.front() += ",";
				steps.front() += target[y - 1];
				solve(x - 1, y - 1);
			}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif	
	while (getline(cin, source)) {
		getline(cin, target);
		if (ok) cout << endl;
		n = sz(source) + 1, m = sz(target) + 1;
		path.clear(), table.clear(), steps.clear();
		value = editDistance(), turn = 0, ok = 1;
		printf("%d\n", value);
		solve(n - 1, m - 1);
		for (int i = 0; i < sz(steps); i++)
			cout << i + 1 << steps[i] << endl;
	}
	return 0;
}