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
#define MAX 1100
int const INF = 0x3f3f3f3f;

int T, r, c;
int maze[MAX][MAX];
bool vis[MAX][MAX];
int dist[MAX][MAX];

struct state_t
{
	state_t() {}
	state_t(int _x, int _y, int _c)
		: x(_x), y(_y), c(_c) {}
	bool operator < (const state_t& s) const
	{
		return this->c < s.c;
	}
	int x, y, c;
};

class compare_t
{
public:
	bool operator() (const state_t& s1, const state_t& s2) const
	{
		return s1.c > s2.c;
	}
};

inline bool ok(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}

int solve(int x, int y)
{
	priority_queue<state_t, vector<state_t>, compare_t> q;
	q.push(state_t(x, y, maze[0][0]));
	while (!q.empty())
	{
		int cx = q.top().x;
		int cy = q.top().y;
		int cost = q.top().c;
		q.pop();
		if (cx == r - 1 && cy == c - 1)
			return cost;
		if (vis[cx][cy]) continue;
		vis[cx][cy] = true;
		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy)
				if ((dx == 0) ^ (dy == 0))
				{
					int _x = dx + cx;
					int _y = dy + cy;
					if (ok(_x, _y))
					{
						int newc = cost + maze[_x][_y];
						if (newc < dist[_x][_y])
						{
							dist[_x][_y] = newc;
							q.push(state_t(_x, _y, dist[_x][_y]));
						}
					}
				}
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; ++i)
		{
			fill(dist[i], dist[i] + c, INF);
			for (int j = 0; j < c; ++j)
				scanf("%d", &maze[i][j]);
		}
		memset(vis, false, sizeof vis);
		printf("%d\n", solve(0, 0));
	}
	return 0;
}