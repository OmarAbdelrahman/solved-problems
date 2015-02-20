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
#define                    MAX							  100000000
#define                zero(A)				memset(A, 0, sizeof(A))
#define                True(A)			 memset(A, true, sizeof(A))
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

template <class _Ty>
class Queue: public queue <_Ty> {
	public:
		_Ty Dequeue() {
			_Ty tmp = queue <_Ty>::front();
			queue <_Ty>::pop();
			return tmp;
		}
};

bool square[MAX + 1];

inline void FillSquares()
{
	For (i, 1, 10001) square[i * i] = true;
}

int main() 
{
	FillSquares();

	int cases;
	string word;
	VS board;

	cin >> cases;
	cin.ignore();

	while (cases--)
	{
		getline(cin, word);

		if (!square[sz(word)])
		{
			puts("INVALID");
			continue;
		}

		int k = 0;
		res(board, sqrtl(sz(word)));

		for (int i = 0; i < sz(board); i++)
		{
			res(board[i], sqrtl(sz(word)));

			for (int j = 0; j < sz(board[i]); j++, k++)
				board[i][j] = word[k];
			
			if (k == sz(word)) break;
		}

		For (i, 0, sz(board))
			For (j, 0, sz(board[i]))
				cout << board[j][i];
		cout << endl;

		c(board);
	}

	return 0;
}