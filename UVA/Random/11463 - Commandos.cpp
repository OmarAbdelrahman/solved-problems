/*
ID: 1010
PROG: kimbits
LANG: C++
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;

typedef long long _int;
typedef vector<int> list_t;
typedef vector<list_t> AdjacentList;
#define MAX 150
int const INF = 0x3f3f3f3f;

int T, nodes, conn;
AdjacentList data;
bool vis[MAX];

template<class T> inline void getMin(T& a, T b)
{
	if (b < a) a = b;
}

template<class T> inline void getMax(T& a, T b)
{
	if (b > a) a = b;
}

void solve(int src, list_t& dist)
{
	dist = list_t(nodes, -1);
	memset(vis, false, sizeof vis);
	queue<int> q; 
	q.push(src);
	dist[src] = 0;
	vis[src] = true;
	while (!q.empty())
	{
		int indx = q.front();
		q.pop();
		for (vector<int>::iterator it = data[indx].begin(); it != data[indx].end(); it++)
			if (!vis[*it])
			{
				vis[*it] = true;
				dist[*it] = dist[indx] + 1;
				q.push(*it);
			}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &T);
	for (int c = 1; T--; ++c)
	{
		scanf("%d%d", &nodes, &conn);
		data = AdjacentList(nodes);
		for (int i = 0; i < conn; ++i)
		{
			int u, v; scanf("%d%d", &u, &v);
			data[u].push_back(v);
			data[v].push_back(u);
		}
		int s, t; scanf("%d%d", &s, &t);
		list_t src, trg;
		solve(s, src);
		solve(t, trg);
		int res = -INF;
		for (int i = 0; i < src.size(); ++i)
			if (src[i] != -1 && trg[i] != -1)
				getMax(res, src[i] + trg[i]);
		printf("Case %d: %d\n", c, res);
	}
	return 0;
}