/*
TASK: ditch
LANG: C++
 */

#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
#include <bitset>
#include <complex>
#include <cassert>
#include <numeric>

using namespace std;

#define eps (1e-12)
#define oo (int)1e9
#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef vector < vector<int> > adj_m;
#define mp                            make_pair
#define pb                            push_back
#define np                            next_permutation
#define c(A)                          A.clear()
#define sz(A)                         ((int)A.size())
#define res(A, n)                     A.resize(n)
#define All(A)                        A.begin(), A.end()
#define F(i, v, Limit)                for (int i = v; i < Limit; i++)
#define DF(i, Limit, v)               for (int i = Limit; i >= v; i--)
#define init(A, B)                    memset(A, B, sizeof(A))
#define VC                            vector
#define PII                           pair <int, int>
#define VI                            VC <int>
#define VS                            VC <string>
#define VVI                           VC <VI>
#define a                             first
#define b                             second
#define VPII                          VC <PII>
#define limit                         31

template <class _Ty> inline _Ty square(_Ty n) {
	return n * n;
}

template <class _Ty> inline _Ty cube(_Ty n) {
	return square(n) * n;
}

vector <vector <int> > cap;
vector <int> flow;
vector <int> parent;

void getapath(int src) {
	parent = flow = vector<int>(cap.size());
	vector <bool> vis(cap.size(),false);

	flow[src] = oo;
	int cur = src;

	while (cur != -1) {
		int next = -1;
		int m = 0;
		vis[cur] = true;

		for (int i = 0; i < (int)cap.size(); i++) {
			if (flow[i] < min(flow[cur], cap[cur][i])) {
				flow[i] = min(flow[cur], cap[cur][i]);
				parent[i] = cur;
			}
			if (flow[i] > m && !vis[i]) {
				next = i;
				m = flow[i];
			}
		}
		cur = next;
	}
}

int max_flow(int src, int destination) {
	if (src == destination)
		return oo;

	int total_flow = 0;

	while (true) {
		getapath(src);

		if (!flow[destination])
			break;

		for (int cur = destination; cur != src; cur = parent[cur]) {
			cap[parent[cur]][cur] -= flow[destination];
			cap[cur][parent[cur]] += flow[destination];
		}
		total_flow += flow[destination];
	}
	return total_flow;
}

int n, m;
int S, E, C;

int main() {
	freopen("ditch.in", "rt", stdin);
	freopen("ditch.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cap = adj_m(m, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &S, &E, &C);
		cap[S - 1][E - 1] += C;
	}
	printf("%d\n", max_flow(0, m - 1));
	return 0;
}














