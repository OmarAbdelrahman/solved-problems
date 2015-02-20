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

#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;

#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;

#else
#include <hash_set>
#include <hash_map>
#endif
#endif

using namespace std;

int _x[] = {-1, 0, 0, 1};
int _y[] = {0, -1, 1, 0};

struct State
{
	int x;
	int y;
	int c;

	State()
	{
		x = y = c = 0;
	}

	State(int x, int y, int c)
	{
		this->x = x;
		this->y = y;
		this->c = c;
	}
}harry, hermonie, current, newState;

class Compare
{
public:
	bool operator () (const State& p1, const State& p2)
    {
        return p1.c > p2.c;
    }
};

int m, n, a, b, T;
int room[101][101];
int distances[101][101];
bool visited[101][101];

inline bool in(int _m, int _n)
{
	return (_m >= 0 && _n >= 0 && _m < m && _n < n);
}

int BFS()
{
	priority_queue <State, vector <State>, Compare> d;
	harry = State(0, 0, room[0][0]);
	d.push(harry);
	while (!d.empty())
	{
		current = d.top();
		d.pop();

		if (current.x == hermonie.x && current.y == hermonie.y)
			return current.c;

		if (visited[current.x][current.y])
			continue;
		visited[current.x][current.y] = true;

		for (int i = 0; i < 4; i++)
		{
			newState.x = current.x + _x[i];
			newState.y = current.y + _y[i];

			if (in(newState.x, newState.y))
			{
				int _n = current.c + room[newState.x][newState.y];
				if (_n < distances[newState.x][newState.y])
				{
					distances[newState.x][newState.y] = _n;
					d.push(State(newState.x, newState.y, _n));
				}
			}
		}
	}
	return -1;
}

int main() 
{
	freopen("in.txt", "r", stdin);

	int _Cases;
	scanf("%d", &_Cases);

	while (_Cases--)
	{
		scanf("%d%d", &m, &n);

		for (int i = 0; i < m; i++)
			fill(distances[i], distances[i] + n, 10000000);

		memset(visited, false, sizeof(visited));

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &room[i][j]);

		scanf("%d%d%d", &a, &b, &T);

		hermonie = State(a - 1, b - 1, 0);

		int _out = BFS();

		if (_out == -1)
			puts("NO");
		else if (_out <= T)
			printf("YES\n%d\n", T - _out);
		else
			puts("NO");
	}

	return 0;
}