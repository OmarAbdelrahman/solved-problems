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

vector <int> dp(9000, 0);
int coins[] = {1, 5, 10, 25, 50}, input;

void solve() {
	dp[0] = dp[1] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = 1; j + coins[i] < sz(dp); j++)
			dp[j + coins[i]] += dp[j];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	solve();
	while (scanf("%d", &input) != EOF) {
		printf("%d\n", dp[++input]);
	}
	return 0;
}
