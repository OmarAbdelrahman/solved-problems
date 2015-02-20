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
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int64;
#define SZ(a) ((int)a.size())
#define FOR(i, s, e) for (int i = s; i < e; ++i)
#define REP(i, e) for (int i = 0; i < e; ++i)
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(c) c.begin(), c.end()
#define MAX 8

struct State
{
	int x, y, c, n;
	State() {}
	State(int x, int y, int c, int n)
	{
		this->x = x;
		this->y = y;
		this->c = c;
		this->n = n;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cases; scanf("%d", &cases);
	while (cases--)
	{
		int n; scanf("%d", &n);
		char g[MAX][MAX];
		bool vis[MAX][MAX][1 << MAX];
		int pieces = 0;
		int kX = -1, kY = -1;
		memset(vis, false, sizeof(vis));
		map<pair<int, int>, int> index;
		for (int i = 0; i < MAX; i++)
		{
			scanf("%s", g[i]);
			for (int j = 0; j < MAX; j++)
				if (g[i][j] == 'p' || g[i][j] == 'K')
					vis[i][j][0] = true;
				else if (g[i][j] == 'P')
					index[make_pair(i, j)] = pieces++;
				else if (g[i][j] == 'k')
					kX = i, kY = j;
		}
		int start = 0;
		for (map<pair<int, int>, int>::iterator it = index.begin(); it != index.end(); it++)
			start |= (1 << it->second);
		queue<State> q;
		q.push(State(kX, kY, 0, start));
		vis[kX][kY][0] = true;
		string res = "X";
		while (!q.empty())
		{
			State now = q.front();
			q.pop();
			if (now.n == 0 && now.c <= n)
			{
				res = "Yes";
				break;
			}
			for (int dx = -2; dx <= 2; dx++)
				for (int dy = -2; dy <= 2; dy++)
					if (abs(dx * dy) == 2)
					{
						int xx = dx + now.x;
						int yy = dy + now.y;
						if (xx >= 0 && xx < MAX && yy >= 0 && yy < MAX)
						{
							if (g[xx][yy] == 'P')
							{
								int nmask = now.n & ~(1 << index[make_pair(xx, yy)]);
								if (!vis[xx][yy][nmask])
									q.push(State(xx, yy, now.c + 1, nmask));
								vis[xx][yy][nmask] = true;
							}
							else if (g[xx][yy] == '.')
							{
								if (!vis[xx][yy][now.n])
									q.push(State(xx, yy, now.c + 1, now.n));
								vis[xx][yy][now.n] = true;
							}
						}
					}
		}
		if (res == "X") res = "No";
		printf("%s\n", res.c_str());
	}
	return 0;
}