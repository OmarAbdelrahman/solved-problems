/*
TASK: ditch
LANG: C++
 */

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;

#define eps                           (1e-12)
#define oo                            (int)1e9
#define All(A)                        A.begin(), A.end()
#define init(A, B)                    memset(A, B, sizeof(A))
#define F(i, v, Limit)                for (int i = v; i < Limit; i++)
#define DF(i, Limit, v)               for (int i = Limit; i >= v; i--)
#define foreach(i, c)                 for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;

vector <int> dist;

void D(AdjacentList& graph, int src)
{
	dist = vector <int>(graph.size(), oo);
	vector <bool> vis(graph.size(), false);

	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
	q.push(make_pair(src, 0));
	dist[src] = 0;

	while (!q.empty())
	{
		int indx = q.top().first;
		int cost = q.top().second;
		q.pop();

		if (vis[indx])
			continue;
		vis[indx] = true;

		foreach (it, graph[indx])
		{
			int newc = cost + it->second;
			if (newc < dist[it->first])
			{
				dist[it->first] = newc;
				q.push(make_pair(it->first, newc));
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
#endif

	int t, src;
	scanf("%d", &t);

	while (t--)
	{
		int cities, a, b, c;
		scanf("%d", &cities);

		AdjacentList graph(cities);
		for (int i = 0; i < cities - 1; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (!i) src = a - 1;
			graph[a - 1].push_back(pair <int, int>(b - 1, c));
			graph[b - 1].push_back(pair <int, int>(a - 1, c));
		}
		D(graph, src);
		src = max_element(All(dist)) - dist.begin();
		D(graph, src);

		printf("%d\n", *max_element(All(dist)));
	}

	return 0;
}