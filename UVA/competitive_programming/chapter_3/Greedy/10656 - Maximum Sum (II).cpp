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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstring;
typedef unsigned int uint;

#define two(n) (1 << (n))
#define on(m, n) (((m) & two(n)) != 0)
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define PB push_back
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define MAX 1000000+5

int main() {
	for (int n; cin >> n && n != 0;) {
		vint res;
		for (int a; n-- != 0;) {
			cin >> a;
			if (a != 0)
				res.PB(a);
		}
		if (res.empty())
			puts("0");
		else {
			cout << res[0];
			FOR(i, 1, SIZE(res))
				cout << " " << res[i];
			cout << endl;
		}
	}
	return 0;
}