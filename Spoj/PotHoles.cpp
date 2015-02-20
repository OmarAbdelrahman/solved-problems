#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

typedef long long i64;
const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
#define all(A) A.begin(), A.end()
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

AdjacentMatrix cap;
vector <int> flow;
vector <int> parent;

void GetPath(int src) 
{
	parent = flow = vector<int>(cap.size());
	vector <bool> vis(cap.size(),false);

	flow[src] = oo;
	int cur = src;

	while (cur != -1) 
	{
		int next = -1;
		int m = 0;
		vis[cur] = true;

		for (int i = 0; i < (int)cap.size(); i++) 
		{
			if (flow[i] < min(flow[cur], cap[cur][i])) 
			{
				flow[i] = min(flow[cur], cap[cur][i]);
				parent[i] = cur;
			}
			if (flow[i] > m && !vis[i]) 
			{
				next = i;
				m = flow[i];
			}
		}
		cur = next;
	}
}

int max_flow(int src, int destination) 
{
	if (src == destination)
		return oo;

	int total_flow = 0;

	while (true) 
	{
		GetPath(src);

		if (!flow[destination])
			break;

		for (int cur = destination; cur != src; cur = parent[cur]) 
		{
			cap[parent[cur]][cur] -= flow[destination];
			cap[cur][parent[cur]] += flow[destination];
		}
		total_flow += flow[destination];
	}
	return total_flow;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	int c;
	scanf("%d", &c);

	while (c--)
	{
		int n;
		scanf("%d", &n);
		cap = AdjacentMatrix(n, vector <int>(n, 0));
		for (int i = 0; i < n - 1; i++)
		{
			int conn;
			scanf("%d", &conn);
			while (conn--)
			{
				int t;
				scanf("%d", &t);
				if (i == 0 || t == n) cap[i][t - 1] = 1;
				else cap[i][t - 1] = oo;
			}
		}
		printf("%d\n", max_flow(0, n - 1));
	}

	return 0;
}