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

typedef unsigned long long int64;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX=50;
int64 const INF=40000000L*60L;

bool conn[MAX+1][MAX+1];
bool v[MAX+1];

vector<vector<int64> > cap;
vector<int64> flow;
vector<int> parent;

void init(int n) {
	cap=vector<vector<int64> >(n,vector<int64>(n,0));
}

void addEdge(int f,int t,int64 c) {
	cap[f][t]=c;
}

void getPath(int src) {
	parent = vector<int>(cap.size());
	flow = vector<int64>(cap.size());
	vector<bool> vis(cap.size(), false);
	flow[src] = INF;
	int cur = src;
	while (cur != -1) {
		int next = -1;
		int64 m = 0;
		vis[cur] = true;
		for (int i = 0; i < SIZE(cap); i++) {
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

void maxFlow(int src, int trg) {
	if (src == trg) return;
	int totalFlow = 0;
	while (true) {
		getPath(src);
		if (!flow[trg]) break;
		for (int cur = trg; cur != src; cur = parent[cur]) {
			cap[parent[cur]][cur] -= flow[trg];
			cap[cur][parent[cur]] += flow[trg];
		}
		totalFlow += flow[trg];
	}
	return;
}

void dfsSrc(int n) {
	v[n]=true;
	for (int i=0;i<SIZE(cap);++i)
		if (cap[n][i]>0 && !v[i])
			dfsSrc(i);
}

int main(int argc, char **argv) {
	int src=0,trg=1;
	for (int n,m;cin>>n>>m;) {
		if (n==0 && m==0) break;
		memset(conn,0,sizeof(conn));
		memset(v,false,sizeof(v));
		init(n+1);
		for (int i=0;i<m;++i) {
			int64 x,y,z; cin>>x>>y>>z;
			addEdge(x-1,y-1,z);
			addEdge(y-1,x-1,z);
			conn[x-1][y-1]=1;
			conn[y-1][x-1]=1;
		}
		maxFlow(src,trg);
		dfsSrc(src);
		for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
			if (conn[i][j] && cap[i][j]==0 && v[i]!=v[j])
				cout<<i+1<<" "<<j+1<<endl;
		}
		cout<<endl;
	}
	return 0;
}

