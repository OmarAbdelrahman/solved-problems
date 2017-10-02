/*
TASK: telecow
LANG: C++
 */

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

int const INF=1<<29;
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define in(i) (2*(i))
#define out(i) (2*(i)+1)
int const MAX=101;
int conn[MAX][MAX];
bool taken[MAX];

vector<vector<int> > cap;
vector<int> flow;
vector<int> parent;

void init(int n) {
	cap.clear();
	cap=vector<vector<int> >(n,vector<int>(n,0));
}

void addEdge(int f,int t,int c) {
	cap[f][t]=c;
}

void getPath(int src) {
	parent = flow = vector<int>(cap.size());
	vector<bool> vis(cap.size(), false);
	flow[src] = INF;
	int cur = src;
	while (cur != -1) {
		int next = -1;
		int m = 0;
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

int maxFlow(int src, int trg) {
	if (src == trg) return INF;
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
	return totalFlow;
}

void connect(int n,int m,int src,int trg) {
	init(2*n+1);
	for (int i=0;i<n;++i) for (int j=0;j<n;++j)
		if (conn[i][j])
			addEdge(out(i),in(j),INF);
	for (int i=0;i<n;++i)
		if (!taken[i]) {
			addEdge(in(i),out(i),1);
			addEdge(out(i),in(i),0);
		}
	addEdge(in(src),out(src),INF);
	addEdge(in(trg),out(trg),INF);
}

int main(int argc, char **argv) {
	freopen("telecow.in","r",stdin);
	freopen("telecow.out","w",stdout);
	int n,m,src,trg; cin>>n>>m>>src>>trg;
	--src,--trg;
	for (int i=0;i<m;++i) {
		int a,b; cin>>a>>b;
		conn[a-1][b-1]=1;
		conn[b-1][a-1]=1;
	}
	memset(taken,false,sizeof(taken));
	connect(n,m,src,trg);
	int minCut=maxFlow(out(src),in(trg));
	int flow=minCut;
	for (int i=0;i<n;++i)
		if (i!=src && i!=trg) {
			taken[i]=true;
			connect(n,m,src,trg);
			int temp=maxFlow(out(src),in(trg));
			taken[i]=false;
			if (temp<flow) {
				flow=temp;
				taken[i]=true;
			}
		}
	cout<<minCut<<endl;
	bool f=true;
	for (int i=0;i<n;++i)
		if (taken[i]) {
			if (f) {
				cout<<i+1;
				f=false;
			} else
				cout<<" "<<i+1;
		}
	cout<<endl;
	return 0;
}