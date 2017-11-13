#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
#define all(A) A.begin(), A.end()
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int x[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int y[] = {0, 0, -1, 1, 1, -1, 1, -1};

int m, n, c;
char ch = '*';
vector <string> board;

bool available(int x, int y) 
{
	return (x >= 0 && y >= 0 && x < m && y < n);
}

void fillboard(int r, int c) 
{
	for (int i = 0; i < (1 << 3); i++)
		if (available(r + x[i], c + y[i]) && board[r + x[i]][c + y[i]] == '@') {
			board[r + x[i]][c + y[i]] = ch;
			fillboard(r + x[i], c + y[i]);
		}
}

int main() 
{
#ifndef ONLINE_JUFGE
	freopen("in.txt", "r", stdin);
#endif
	while (cin >> m >> n && m != 0) {
		#define size(a) ((int)a.size())
		c = 0, board.resize(m);
		for (int i = 0; i < size(board); i++) {
			cin >> board[i];
			board[i].resize(n);
		}
		for (int i = 0; i < size(board); i++)
			for (int j = 0; j < size(board[i]); j++)
				if (board[i][j] == '@') c++, fillboard(i, j);
		printf("%d\n", c);
	}
	return 0;
}