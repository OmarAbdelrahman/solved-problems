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

#define                size(A)					    ((int)A.size())
#define                 All(A)					 A.begin(), A.end()
#define		  For(i, v, Limit)		for (int i = v; i < Limit; i++)
#define      DFor(i, Limit, v)     for (int i = Limit; i >= v; i--)
#define                    MAX									 31

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;
typedef            long double							LongDouble;

using namespace std;

template <class _Ty>
class Queue: public queue <_Ty> {
	public:
		_Ty Dequeue() {
			_Ty tmp = queue <_Ty>::front();
			queue <_Ty>::pop();
			return tmp;
		}
};

int row, col;

struct Plate 
{
	int x;
	int y;
	int time;
	bool north;
	bool east;
	bool south;
	bool west;
};

string dir;
bool check;
bool taken[501][501][4];
vector <vector <Plate> > board;
Plate temp;

bool available(int x, int y) 
{
	return (x >= 0 && y >= 0 && x < row && y < col);
}

void checktime(int);
void rotateone();
void rotatetwo();
void rotatethree();
int getminimum();

int main() 
{
	while (cin >> row >> col) 
	{
		check = false;
		memset(taken, false, sizeof(bool)*501*501*4);

		temp.x = 0, temp.y = 0, temp.time = 0;
		temp.north = false, temp.east = false;
		temp.south = false, temp.west = false;

		board.resize(row);
		for (int i = 0; i < row; i++) 
		{
			board[i].resize(col);
			for (int j = 0; j < col; j++) 
			{
				board[i][j].x = i, board[i][j].y = j;
				if (i == row - 1 && j == col - 1) 
				{
					check = true;
					break;
				}
				cin >> dir;
				for (int k = 0; k < size(dir); k++) 
				{
					switch (dir[k]) 
					{
						case 'N': board[i][j].north = true; break;
						case 'E': board[i][j].east  = true; break;
						case 'S': board[i][j].south = true; break;
						case 'W': board[i][j].west  = true; break;
					}
				}
			}
			if (check) break;
		}
		int n = getminimum();
		if (n == -1) puts("no path to exit");
		else cout << n << endl;
		board.clear();
	}
	return 0;
}

void rotateone() 
{
	bool rotate[4];

	rotate[0] = temp.north;
	rotate[1] = temp.east;
	rotate[2] = temp.south;
	rotate[3] = temp.west;

	temp.north = rotate[3];
	temp.east  = rotate[0];
	temp.south = rotate[1];
	temp.west  = rotate[2];
}

void rotatetwo() 
{
	bool rotate[4];

	rotate[0] = temp.north;
	rotate[1] = temp.east;
	rotate[2] = temp.south;
	rotate[3] = temp.west;

	temp.north = rotate[2];
	temp.east  = rotate[3];
	temp.south = rotate[0];
	temp.west  = rotate[1];
}

void rotatethree() 
{
	bool rotate[4];

	rotate[0] = temp.north;
	rotate[1] = temp.east;
	rotate[2] = temp.south;
	rotate[3] = temp.west;

	temp.north = rotate[1];
	temp.east  = rotate[2];
	temp.south = rotate[3];
	temp.west  = rotate[0];
}

void checktime(int t) 
{
	switch (t) 
	{
		case 1: rotateone(); break;
		case 2: rotatetwo(); break;
		case 3: rotatethree(); break;
	}
}

int getminimum() 
{
	board[0][0].time = 0;
	Queue <Plate> bfs;
	bfs.push(board[0][0]);
	taken[0][0][0] = true;

	Plate cur;
	while (!bfs.empty()) 
	{
		cur = bfs.Dequeue();
		if (cur.x == row - 1 && cur.y == col - 1)
			return cur.time;

		temp = cur;
		checktime(cur.time % 4);

		if (temp.north) 
		{
			if (available(cur.x - 1, cur.y)) 
				if (!taken[cur.x - 1][cur.y][cur.time % 4]) 
				{
					board[cur.x - 1][cur.y].time = cur.time + 1;
					taken[cur.x - 1][cur.y][cur.time % 4] = true;
					bfs.push(board[cur.x - 1][cur.y]);
				}
		}
		if (temp.east) 
		{
			if (available(cur.x, cur.y + 1))
				if (!taken[cur.x][cur.y + 1][cur.time % 4]) 
				{
					board[cur.x][cur.y + 1].time = cur.time + 1;
					taken[cur.x][cur.y + 1][cur.time % 4] = true;
					bfs.push(board[cur.x][cur.y + 1]);
				}
		}
		if (temp.south) 
		{
			if (available(cur.x + 1, cur.y))
				if (!taken[cur.x + 1][cur.y][cur.time % 4]) 
				{
					board[cur.x + 1][cur.y].time = cur.time + 1;
					taken[cur.x + 1][cur.y][cur.time % 4] = true;
					bfs.push(board[cur.x + 1][cur.y]);
				}
		}
		if (temp.west) 
		{
			if (available(cur.x, cur.y - 1))
				if (!taken[cur.x][cur.y - 1][cur.time % 4]) 
				{
					board[cur.x][cur.y - 1].time = cur.time + 1;
					taken[cur.x][cur.y - 1][cur.time % 4] = true;
					bfs.push(board[cur.x][cur.y - 1]);
				}
		}
	}
	return -1;
}