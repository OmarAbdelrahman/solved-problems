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

using namespace std;

int r, c;

struct State
{
	int x;
	int y;
	int c;
};

bool ok(int _x, int _y)
{
	return _x >= 0 && _y >= 0 && _x < r && _y < c;
}

char board[101][101];
bool taken[101][101];
int kX[] = {-2, -1, -2, -1, 1, 2, 1, 2};
int kY[] = {-1, -2, 1, 2, -2, -1, 2, 1};
int qX[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int qY[] = {0, 0, -1, 1, 1, -1, -1, 1};

void solve(State start)
{
	queue<State> bfs;
	bfs.push(start);
	while (!bfs.empty())
	{
		State cur = bfs.front();
		bfs.pop();
		if (board[cur.x][cur.y] == 'B')
		{
			printf("Minimal possible length of a trip is %d\n", cur.c);
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			if (ok(cur.x + qX[i], cur.y + qY[i]) && !taken[cur.x + qX[i]][cur.y + qY[i]])
			{
				State temp = {cur.x + qX[i], cur.y + qY[i], cur.c + 1};
				bfs.push(temp);
				taken[cur.x + qX[i]][cur.y + qY[i]] = true;
			}
		}
	}
	puts("King Peter, you can't go now!");
}

int main()
{
	int T; scanf("%d", &T);
	while (T-- != 0)
	{
		int y, z; cin >> r >> c;
		memset(taken, false, sizeof(taken));
		State start;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 'A')
				{
					start.x = i;
					start.y = j;
					start.c = 0;
					taken[i][j] = true;
				}
				else if (board[i][j] == 'B')
				{
					y = i;
					z = j;
				}
				else if (board[i][j] == 'Z')
				{
					taken[i][j] = true;
					for (int k = 0; k < 8; k++)
						if (ok(i + kX[k], j + kY[k]))
							if (!taken[i + kX[k]][j + kY[k]])
								taken[i + kX[k]][j + kY[k]] = true;
				}
			}
		taken[y][z] = false;
		solve(start);
	}
	return 0;
}