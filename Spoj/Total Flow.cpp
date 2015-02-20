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
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

AdjacentMatrix cap;

vector <int> flow;
vector <int> parent;

void GetPath(int src) 
{
	parent = flow = vector <int>(cap.size());
	vector <bool> vis(cap.size(), false);

	flow[src] = oo;
	int cur = src;

	while (cur != -1) 
	{
		int next = -1, m = 0;
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

int res = 0;
map <char, int> values;

void Initialize()
{
	for (char i = 'A'; i <= 'Z'; i++)
		values[i] = res++;
	for (char i = 'a'; i <= 'z'; i++)
		values[i] = res++;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	char a, b;
	int nodes, c;
	Initialize();

	while (scanf("%d", &nodes) != EOF)
	{
		cap = AdjacentMatrix(res + 2, vector <int>(res + 2, 0));

		for (int i = 0; i < nodes; i++)
		{
			cin >> a >> b >> c;
			cap[values[a]][values[b]] += c;
			cap[values[b]][values[a]] += c;
		}

		printf("%d\n", max_flow(values['A'], values['Z']));
	}

	return 0;
}