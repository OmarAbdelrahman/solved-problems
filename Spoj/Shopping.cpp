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
#define sz(A)                         ((int)A.size())
#define All(A)                        A.begin(), A.end()
#define init(A, B)                    memset(A, B, sizeof(A))
#define F(i, v, Limit)                for (int i = v; i < Limit; i++)
#define DF(i, Limit, v)               for (int i = Limit; i >= v; i--)
#define foreach(i, c)                 for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;

char c;
int w, h;
int _x[] = {-1, 1, 0, 0};
int _y[] = {0, 0, -1, 1};
char graph[26][26];

bool ok(int _h, int _w)
{
	return (_w >= 0 && _h >= 0 && _w < w && _h < h);
}

struct State
{
	int x, y, c;
	State() {}
	State(int xx, int yy, int cc): x(xx), y(yy), c(cc)
		{}
}start, end, current;

class Compare
{
public:
	bool operator () (const State& s1, const State& s2)
	{
		return s1.c > s2.c;
	}
};

void D()
{
	AdjacentMatrix dist(h, vector <int>(w, oo));
	vector <vector <bool> > vis(h, vector <bool>(w, false));

	priority_queue <State, vector <State>, Compare> q;
	q.push(start);

	dist[start.x][start.y] = 0;

	while (!q.empty())
	{
		current = q.top();
		q.pop();

		if (vis[current.x][current.y])
			continue;
		vis[current.x][current.y] = true;

		for (int i = 0; i < 4; i++)
		{
			int xx = current.x + _x[i];
			int yy = current.y + _y[i];

			if (ok(xx, yy))
			{
				if (graph[xx][yy] == 'X')
					continue;
				if (graph[xx][yy] == 'D')
					return;

				int newc = current.c + (graph[xx][yy] - '0');
				if (newc < dist[xx][yy])
				{
					dist[xx][yy] = newc;
					q.push(State(xx, yy, newc));
				}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif

	while (scanf("%d%d", &w, &h) != EOF && (w && h))
	{
		for (int i = 0; i < h; i++)
		{
			scanf("%s", graph[i]);
			for (int j = 0; j < w; j++)
				if (graph[i][j] == 'S')
					start = State(i, j, 0);
				else if (graph[i][j] == 'D')
					end = State(i, j, 0);
		}
		D();
		printf("%d\n", current.c);
	}
}