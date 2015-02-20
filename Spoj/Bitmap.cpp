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
using namespace std;

#define sz(A) ((int)A.size())

int _x[] = {-1, 1, 0, 0};
int _y[] = {0, 0, 1, -1};

struct State 
{
	int x, y, c;
	State() { }
	State(int x, int y, int c) 
	{
		this->x = x;
		this->y = y;
		this->c = c;
	}
};

int r, c;
vector <string> board;
int results[200][200];
bool visited[200][200];

bool available(int _r, int _c) 
{
	return (_r >= 0 && _c >= 0 && _r < r && _c < c);
}

void BFS(queue <State>& bfs)
{
	State current;
	for (; !bfs.empty(); bfs.pop()) 
	{
		current = bfs.front();
		results[current.x][current.y] = min(results[current.x][current.y], current.c);
		for (int i = 0; i < 4; i++) 
			if (available(current.x + _x[i], current.y + _y[i])) 
				if (!visited[current.x + _x[i]][current.y + _y[i]] && board[current.x + _x[i]][current.y + _y[i]] != '1')
				{
					visited[current.x + _x[i]][current.y + _y[i]] = true;
					bfs.push(State(current.x + _x[i], current.y + _y[i], current.c + 1));
				}
	}
}

inline void Display()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			(j == c - 1) ? printf("%d\n", results[i][j]) : printf("%d ", results[i][j]);
}

int main() 
{
	int cases;
	scanf("%d", &cases);
	while (cases--) 
	{
		scanf("%d%d", &r, &c);
		queue<State> bfs;
		for (int i = 0; i < r; i++)
		{
			fill(results[i], results[i] + c, 1000000);
			fill(visited[i], visited[i] + c, false);
		}
		board.resize(r);
		for (int i = 0; i < sz(board); i++)
			cin >> board[i];
		for (int i = 0; i < sz(board); i++)
			for (int j = 0; j < sz(board[i]); j++)
				if (board[i][j] == '1') 
				{
					bfs.push(State(i, j, 0));
					visited[i][j] = true;
					results[i][j] = 0;
				}
		BFS(bfs);
		Display();
	}
	return 0;
}