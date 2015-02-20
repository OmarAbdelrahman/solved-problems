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
#define					 sz(A)					    ((int)A.size())
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

template <class _Ty>
class Queue: public queue <_Ty> {
	public:
		_Ty Dequeue() {
			_Ty tmp = queue <_Ty>::front();
			queue <_Ty>::pop();
			return tmp;
		}
};

VS puz;
string dir;
string in;
int cases = 1;

bool available(int x, int y)
{
	return (x >= 0 && y >= 0 && x < 5 && y < 5);
}

void getfinal(int i, int j)
{
	bool check = false;
	For (k, 0, sz(dir))
	{
		if (dir[k] == 'A')
		{
			if (!available(i - 1, j))
			{
				check = true;
				break;
			}
			swap(puz[i][j], puz[i - 1][j]);
			i = i - 1;
		}
		else if (dir[k] == 'B')
		{
			if (!available(i + 1, j))
			{
				check = true;
				break;
			}
			swap(puz[i][j], puz[i + 1][j]);
			i = i + 1;
		}
		else if (dir[k] == 'L')
		{
			if (!available(i, j - 1))
			{
				check = true;
				break;
			}
			swap(puz[i][j], puz[i][j - 1]);
			j = j - 1;
		}
		else if (dir[k] == 'R')
		{
			if (!available(i, j + 1))
			{
				check = true;
				break;
			}
			swap(puz[i][j], puz[i][j + 1]);
			j = j + 1;
		}
		else
		{
			check = true;
			break;
		}
	}
	printf("Puzzle #%d:\n", cases);
	if (check)
	{
		puts("This puzzle has no final configuration.");
	}
	else
	{
		For (r, 0, sz(puz))
		{
			For (c, 0, sz(puz[r]))
			{
				if (c == sz(puz[r]) - 1)
					cout << puz[r][c];
				else
					cout << puz[r][c] << ' ';
			}
			cout << endl;
		}
	}
}

int main()
{
	int cn = 0;
	bool flag = false;
	while (getline(cin, in) && in != "Z")
	{
		puz.push_back(in);
		cn++;
		if (cn == 5)
		{
			if (flag) cout << endl;

			char ch;
			while (cin >> ch && ch != '0')
				dir += ch;

			int x, y;
			bool check = 0;
			For (i, 0, sz(puz))
			{
				For (j, 0, sz(puz[i]))
					if (puz[i][j] == ' ')
					{
						x = i, y = j;
						check = true;
					}
				if (check) break;
			}
			getfinal(x, y);

			cn = 0;
			c(puz);
			dir = "";
			cin.ignore();
			cases++;
			flag = true;
		}
	}
	return 0;
}