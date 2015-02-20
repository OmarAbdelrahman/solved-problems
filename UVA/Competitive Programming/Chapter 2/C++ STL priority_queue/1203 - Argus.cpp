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

typedef long long int64;
#define LENGTH(s) ((int)s.length())
#define SIZE(s) ((int)s.size())
int const MAX = 100 + 1;

struct state {
	int num;
	int64 period;
	state(int n, int64 p):
		num(n), period(p) {}
};

class comparator {
public:
	bool operator () (const state &s1, const state &s2) {
		if (s1.period != s2.period)
			return s1.period > s2.period;
		return s1.num > s2.num;
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	map<int, int64> period;
	priority_queue<state, vector<state>, comparator> q;
	for (string s; cin >> s && s != "#";) {
		int num; cin >> num;
		int64 cperiod; cin >> cperiod;
		period[num] = cperiod;
		q.push(state(num, cperiod));
	}
	int k; cin >> k;
	for (int curN = 0; curN < k && !q.empty(); ++curN, q.pop()) {
		state now = q.top();
		cout << now.num << endl;
		q.push(state(now.num, q.top().period + period[now.num]));
	}
	return 0;
}

