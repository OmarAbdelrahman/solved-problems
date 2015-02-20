/*
ID: 1010
PROG: beads
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

#define       size(A)						((int)A.size())
#define        All(A)					 A.begin(), A.end()
#define For(i, Limit)		for (int i = 0; i < Limit; i++)
#define			LIMIT									 81

typedef     long long	   						   LongInt;
typedef   long double							LongDouble;

using namespace std;

int N;

struct State
{
	int x;
	int y;
};

bool avaialable(int x, int y)
{
	return (x >= 0 && y >= 0 && x < N && y < N);
}

vector <string> Board;
bool visited[LIMIT][LIMIT];

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

bool checkU(int, int, char);
bool whitePath();
bool blackPath();
bool whiteOneMove();
bool blackOneMove();

int main()
{
	freopen("sa3edny_yarab.txt", "r", stdin);
	while (cin >> N && N != 0)
	{
		Board.resize(N);
		for (int i = 0; i < size(Board); i++)
			cin >> Board[i];
		
		if (N == 1 && Board[0][0] == 'U') {
			puts("White can win in one move.");
			continue;
		}
		
		if (whitePath()) {
			puts("White has a winning path.");
			memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
		} else if (blackPath()) {
			puts("Black has a winning path.");
			memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
		} else if (whiteOneMove()) {
			puts("White can win in one move.");
			memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
		} else if (blackOneMove()) {
			puts("Black can win in one move.");
			memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
		} else {
			puts("There is no winning path.");
			memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
		}
	}
	return 0;
}

bool checkU(int x, int y, char ch)
{
	if (ch == 'W')
	{
		for (int i = y + 1; i < N; i++)
			if (Board[x][i] != 'W')
				return false;
		return true;
	}
	else
	{
		for (int i = x + 1; i < N; i++)
			if (Board[i][y] != 'B')
				return false;
		return true;
	}
}

bool whiteOneMove()
{
	State start;
	State current;
	bool secondTime;

	for (int j = 0; j < N; j++)
	{
		secondTime = false;
		start.x = j, start.y = 0;

		if (Board[j][0] == 'B')
			continue;

		if (Board[j][0] == 'U')
		{
			if (checkU(j, 0, 'W'))
				return true;
			continue;
		}

		queue <State> bfs;
		bfs.push(start);
		
		visited[start.x][start.y] = true;

		while (!bfs.empty())
		{
			current = bfs.front();
			
			if (current.y == N - 1 && Board[current.x][current.y] == 'U')
				return true;
			else if (current.y == N - 1)
				break;

			bfs.pop();
			for (int i = 0; i < 4; i++)
			{
				if (avaialable(current.x + X[i], current.y + Y[i]))
				{
					if (!visited[current.x + X[i]][current.y + Y[i]])
					{
						if (Board[current.x + X[i]][current.y + Y[i]] == 'W')
						{
							State temp = { current.x + X[i], current.y + Y[i] };
							visited[current.x + X[i]][current.y + Y[i]] = true;
							bfs.push(temp);
						}
						else if (Board[current.x + X[i]][current.y + Y[i]] == 'U')
							if (checkU(current.x + X[i], current.y + Y[i], 'W'))
								return true;
					}
				}
			}
		}
		memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
	}
	return false;
}

bool blackOneMove()
{
	State start;
	State current;
	bool secondTime;

	for (int j = 0; j < N; j++)
	{
		secondTime = false;
		start.x = 0, start.y = j;

		if (Board[0][j] == 'W')
			continue;

		if (Board[0][j] == 'U') 
		{
			if (checkU(0, j, 'B'))
				return true;
			continue;
		}

		queue <State> bfs;
		bfs.push(start);
		
		visited[start.x][start.y] = true;

		while (!bfs.empty())
		{
			current = bfs.front();
			
			if (current.x == N - 1 && Board[current.x][current.y] == 'U')
				return true;
			else if (current.x == N - 1)
				break;

			bfs.pop();
			for (int i = 0; i < 4; i++)
			{
				if (avaialable(current.x + X[i], current.y + Y[i]))
				{
					if (!visited[current.x + X[i]][current.y + Y[i]])
					{
						if (Board[current.x + X[i]][current.y + Y[i]] == 'B')
						{
							State temp = { current.x + X[i], current.y + Y[i] };
							visited[current.x + X[i]][current.y + Y[i]] = true;
							bfs.push(temp);
						}
						else if (Board[current.x + X[i]][current.y + Y[i]] == 'U')
							if (checkU(current.x + X[i], current.y + Y[i], 'B'))
								return true;
					}
				}
			}
		}
		memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
	}
	return false;
}

bool whitePath()
{
	State start;
	State current;

	for (int j = 0; j < N; j++)
	{
		start.x = j, start.y = 0;

		if (Board[j][0] != 'W')
			continue;

		queue <State> bfs;
		bfs.push(start);

		visited[start.x][start.y] = true;

		while (!bfs.empty())
		{
			current = bfs.front();

			if (current.y == N - 1)
				return true;

			bfs.pop();
			for (int i = 0; i < 4; i++)
			{
				if (avaialable(current.x + X[i], current.y + Y[i]))
				{
					if (!visited[current.x + X[i]][current.y + Y[i]])
					{
						if (Board[current.x + X[i]][current.y + Y[i]] == 'W')
						{
							State temp = { current.x + X[i], current.y + Y[i] };
							visited[current.x + X[i]][current.y + Y[i]] = true;
							bfs.push(temp);
						}
					}
				}
			}
		}
		memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
	}
	return false;
}

bool blackPath()
{
	State start;
	State current;

	for (int j = 0; j < N; j++)
	{
		start.x = 0, start.y = j;

		if (Board[0][j] != 'B')
			continue;

		queue <State> bfs;
		bfs.push(start);

		visited[start.x][start.y] = true;

		while (!bfs.empty())
		{
			current = bfs.front();

			if (current.x == N - 1)
				return true;

			bfs.pop();
			for (int i = 0; i < 4; i++)
			{
				if (avaialable(current.x + X[i], current.y + Y[i]))
				{
					if (!visited[current.x + X[i]][current.y + Y[i]])
					{
						if (Board[current.x + X[i]][current.y + Y[i]] == 'B')
						{
							State temp = { current.x + X[i], current.y + Y[i] };
							visited[current.x + X[i]][current.y + Y[i]] = true;
							bfs.push(temp);
						}
					}
				}
			}
		}
		memset(visited, false, sizeof(bool)*LIMIT*LIMIT);
	}
	return false;
}