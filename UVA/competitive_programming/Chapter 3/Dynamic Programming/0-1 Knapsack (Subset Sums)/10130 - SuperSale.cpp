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

vector <int> values;
vector <int> weight, sum;

int KnapSack(const int W) {
	vector <vector <int> > table;
	table = vector <vector <int> >(sz(values) + 1, vector <int>(W + 1, 0));
	for (int i = 1; i < sz(values) + 1; ++i)
		for (int w = 1; w <= W; ++w) {
			if (weight[i - 1] > w) {
				table[i][w] = table[i - 1][w];
			} else {
				table[i][w] = max(table[i - 1][w], values[i - 1] + table[i - 1][w - weight[i - 1]]);
			}
		}
	return table[sz(values)][W];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		int items;
		scanf("%d", &items);
		while (items--) {
			int v, w;
			scanf("%d%d", &v, &w);
			values.push_back(v);
			weight.push_back(w);
		}
		int f;
		scanf("%d", &f);
		while (f--) {
			int k; scanf("%d", &k);
			sum.push_back(KnapSack(k));
		}
		printf("%d\n", accumulate(all(sum), 0));
		sum.clear();
		values.clear();
		weight.clear();
	}
	return 0;
}
