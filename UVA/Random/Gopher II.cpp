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

adj_m cap;
vector <int> flow;
vector <int> parent;

void GetPath(int src) {
	parent = flow = vector<int>(cap.size());
	vector <bool> vis(cap.size(),false);
	flow[src] = oo;
	int cur = src;
	while (cur != -1) {
		int next = -1, m = 0;
		vis[cur] = true;
		for (int i = 0; i < (int)cap.size(); i++) {
			if (flow[i] < min(flow[cur],cap[cur][i])) {
				flow[i] = min(flow[cur],cap[cur][i]);
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

int max_flow(int src, int sink) {
	if (src == sink) return oo;
	int total_flow = 0;
	while (true) {
		GetPath(src);
		if (!flow[sink]) break;
		for (int cur = sink; cur != src; cur = parent[cur]) {
			cap[parent[cur]][cur] -= flow[sink];
			cap[cur][parent[cur]] += flow[sink];
		}
		total_flow += flow[sink];
	}
	return total_flow;
}

int n, m, s, v;
vector < pair <double, double> > p;

int main() {
	freopen("in.txt", "rt", stdin);
	while (scanf("%d%d%d%d", &n, &m, &s, &v) != EOF) {
		p.resize(n + m);
		cap = adj_m(n + m + 2, vector<int>(n + m + 2, 0));
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &p[i].first, &p[i].second);
			cap[n + m][i] = 1;
		}
		for (int i = n; i < m + n; i++) {
			scanf("%lf%lf", &p[i].first, &p[i].second);
			cap[i][n + m + 1] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = n; j < n + m; j++) {
				double x = p[i].first - p[j].first;
				double y = p[i].second - p[j].second;
				double dist = sqrt(square(y) + square(x));
				if (dist / v + eps > s) continue;
				cap[i][j] = 1;
			}
		}
		printf("%d\n", n - max_flow(n + m, n + m + 1));
	}
	return 0;
}














