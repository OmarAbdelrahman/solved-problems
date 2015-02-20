#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int const MAX = 35;
int L, R, C;

struct State
{
	int x;
	int y;
	int z;
	int c;
};

bool check(int x, int y, int z)
{
	return x >= 0 && y >= 0 && z >= 0 && x < L && y < R && z < C;
}

char board[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

int X[] = {1, -1, 0, 0, 0, 0};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {0, 0, 0, 0, 1, -1};

int main()
{
	bool reached = false;
	while (cin >> L >> R >> C)
	{
		reached = false;
		if (L == 0 && R == 0 && C == 0)
			return 0;
		memset(visited, false, sizeof(visited));
		State start, toreach;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++)
				{
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S')
					{
						start.x = i;
						start.y = j;
						start.z = k;
						start.c = 0;
					}
					if (board[i][j][k] == 'E')
					{
						toreach.x = i;
						toreach.y = j;
						toreach.z = k;
						toreach.c = 0;
					}
				}
			}
		}
		queue<State> BFS;
		BFS.push(start);
		while (!BFS.empty())
		{
			State current = BFS.front();
			if (current.x == toreach.x && current.y == toreach.y && current.z == toreach.z)
			{
				cout << "Escaped in " << current.c << " minute(s)." << endl;
				reached = true;
				break;
			}
			BFS.pop();
			for (int i = 0; i < 6; i++)
			{
				int nx = current.x + X[i];
				int ny = current.y + Y[i];
				int nz = current.z + Z[i];
				if (check(nx, ny, nz))
				{
					if ((!visited[nx][ny][nz]) && board[nx][ny][nz] != '#')
					{
						State temp = {nx, ny, nz, current.c + 1};
						BFS.push(temp);
						visited[nx][ny][nz] = true;
					}
				}
			}
		}
		if (!reached) puts("Trapped!");
	}
	return 0;
}