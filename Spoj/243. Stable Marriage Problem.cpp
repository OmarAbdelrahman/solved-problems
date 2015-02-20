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

int const MAXN = 505;

int man_woman[MAXN][MAXN];
int woman_man[MAXN][MAXN];
int prefer_value[MAXN][MAXN];
int M[MAXN];
int W[MAXN];

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int woman; scanf("%d", &woman);
			for (int j = 0; j < n; ++j) {
				scanf("%d", &woman_man[woman - 1][j]);
				--woman_man[woman - 1][j];
				prefer_value[woman - 1][woman_man[woman - 1][j]] = j;
			}
		}
		for (int i = 0; i < n; ++i) {
			int man; scanf("%d", &man);
			for (int j = 0; j < n; ++j) {
				scanf("%d", &man_woman[man - 1][j]);
				--man_woman[man - 1][j];
			}
		}
		memset(M, -1, sizeof M);
		memset(W, -1, sizeof W);
		queue<int> un_matched;
		for (int man = 0; man < n; ++man)
			un_matched.push(man);
		for (; !un_matched.empty(); un_matched.pop()) {
			int man = un_matched.front();
			for (int i = 0; i < n; ++i) {
				int woman = man_woman[man][i];
				if (W[woman] == -1) {
					W[woman] = man;
					M[man] = woman;
					break;
				} else {
					if (prefer_value[woman][man] < prefer_value[woman][W[woman]]) {
						un_matched.push(W[woman]);
						M[man] = woman;
						W[woman] = man;
						break;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
			printf("%d %d\n", i + 1, M[i] + 1);
	}
	return 0;
}