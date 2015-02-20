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

#define REFUND 200
vector<int> values;
vector<int> weight;
AdjacentMatrix table;
int money, items;

int solve(int index, int remainder) {
	int& answer = table[index][remainder];
	if (index == sz(values)) {
		int diff = money + REFUND - remainder;
		if (diff > money && diff <= 2000)
			return -oo;
		return 0;
	}
	if (answer != -1) return answer;
	answer = solve(index + 1, remainder);
	if (remainder - weight[index] >= 0)
		answer = max(answer, values[index] + solve(index + 1, remainder - weight[index]));
	return answer;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while (scanf("%d%d", &money, &items) != EOF) {
		while (items--) {
			int w, v;
			scanf("%d%d", &w, &v);
			weight.push_back(w);
			values.push_back(v);
		}
		table = AdjacentMatrix(sz(values) + 1, vector <int>(money + REFUND + 1, -1));
		printf("%d\n", solve(0, money + REFUND));
		values.clear(), weight.clear();
	}
	return 0;
}