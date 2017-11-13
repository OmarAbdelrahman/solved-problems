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

#define                   c(A)							  A.clear()
#define                  sz(A)					    ((int)A.size())
#define              res(A, n)							A.resize(n)
#define                 All(A)					 A.begin(), A.end()
#define		  For(i, v, Limit)		for (int i = v; i < Limit; i++)
#define      DFor(i, Limit, v)     for (int i = Limit; i >= v; i--)
#define                    MAX									 31
#define                zero(A)				memset(A, 0, sizeof(A))
#define            negative(A)			   memset(A, -1, sizeof(A))
#define						VC								 vector
#define					   PII						pair <int, int>
#define                     VI						       VC <int>
#define                     VS					        VC <string>
#define                    VVI								VC <VI>
#define						 X								  first
#define                      Y								 second
#define                   VPII							   VC <PII>
#define					 DB(a)	   cerr << #a << ": " << a << endl;

typedef           unsigned int								  uint;
typedef          long long int   						   longint;
typedef unsigned long long int 						      ulongint;
typedef            long double							longdouble;

using namespace std;

VS board;
int r, c;

int x[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int y[] = {0, 0, 1, -1, -1, 1, 1, -1};

bool available(int i, int j) {
	return (i >= 0 && j >= 0 && i < r && j < c);
}

bool valid(int m, int n) {
	For (i, 0, 8)
		if (available(m + x[i], n + y[i]))
			if (board[m + x[i]][n + y[i]] == '*')
				return false;
	return true;
}

int main() {
	int cn;
	while (cin >> r >> c && (r != 0 && c != 0)) {
		res(board, r), cn = 0;
		For (i, 0, sz(board)) {
			cin >> board[i];
			res(board[i], c);
		}
		For (i, 0, sz(board))
			For (j, 0, sz(board[i]))
				if (board[i][j] == '*') if (valid(i, j)) cn++;
		printf("%d\n", cn);
	}
	return 0;
}