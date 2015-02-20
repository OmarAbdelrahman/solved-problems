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

int const MAXN = 10000 + 5;
int const BIG_NUM = 0x3f3f3f3f;

vector<int> adj[MAXN];
int freq[MAXN];

int solve(int src, int n) {
	vector<int> dist(n + 1, BIG_NUM);
	queue<int> q;
	dist[src] = 0;
	for (q.push(src); !q.empty(); q.pop()) {
		int index = q.front();
		for (int i = 0; i < adj[index].size(); ++i) {
			int next = adj[index][i];
			if (dist[next] == BIG_NUM) {
				dist[next] = dist[index] + 1;
				q.push(next);
			}
		}
	}
	int result = 0;
	for (int i = 1; i < dist.size(); ++i)
		if (freq[i] >= 2)
			result += dist[i];
	return result;
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		int cur_max = INT_MIN;
		memset(freq, 0, sizeof(freq));
		int n, e; scanf("%d%d", &n, &e);
		for (int i = 0; i < MAXN; ++i)
			adj[i].clear();
		for (int i = 0; i < e; ++i) {
			int a, b;
			scanf("%d", &a);
			freq[a]++;
			while (scanf("%d", &b) && b > 0) {
				freq[b]++;
				adj[a].push_back(b);
				adj[b].push_back(a);
				cur_max = max(cur_max, max(a, b));
				a = b;
			}
		}
		int index = -1;
		int small = INT_MAX;
		for (int i = 1; i <= cur_max; ++i)
			if (freq[i] >= 2) {				
				int answer = solve(i, cur_max);
				if (answer < small) {
					small = answer;
					index = i;
				}
			}
		printf("Krochanska is in: %d\n", index);
	}
	return 0;
}