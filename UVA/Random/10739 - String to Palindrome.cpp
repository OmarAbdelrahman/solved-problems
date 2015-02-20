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
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int editDistance(string& a, string& b) {
	AdjacentMatrix table;
	table = AdjacentMatrix(sz(a) + 1, vector <int>(sz(b) + 1, 0));
	for (int i = 0; i < sz(table); ++i) {
		table[i][0] = i;
	}
	for (int i = 0; i < sz(table[0]); ++i) {
		table[0][i] = i;
	}
	for (int i = 1; i < sz(table); ++i)
		for (int j = 1; j < sz(table[0]); ++j) {
			if (a[i - 1] == b[j - 1]) {
				table[i][j] = table[i - 1][j - 1];
			} else {
				int deletion = table[i - 1][j] + 1;
				int insertion = table[i][j - 1] + 1;
				int replace = table[i - 1][j - 1] + 1;
				table[i][j] = min(insertion, min(deletion, replace));
			}
		}
	return table[sz(a)][sz(b)];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cases;
	scanf("%d", &cases);
	for (int turn = 1; turn <= cases; ++turn) {
		string input; cin >> input;
		string rinput = input;
		reverse(all(rinput));
		printf("Case %d: %d\n", turn, editDistance(input, rinput) >> 1);
	}
	return 0;
}
