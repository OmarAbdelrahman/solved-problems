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
#define                  limit									102
#define                Zero(A)				memset(A, 0, sizeof(A))
#define                True(A)			 memset(A, true, sizeof(A))
#define            Negative(A)			   memset(A, -1, sizeof(A))
#define             Filladj(A)		   memset(A, 100000, sizeof(A))
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

PII pages;
int adjMatrix[limit][limit];
double counter, sum;
int _Maximum;
double average;

int main() 
{
	for (int cases = 1; cin >> pages.X >> pages.Y && (pages.X && pages.Y); cases++)
	{
		For (i, 0, limit) fill(adjMatrix[i], adjMatrix[i] + limit, 100000);
		
		_Maximum = counter = sum = 0.0;
		_Maximum = max(_Maximum, pages.X);
		_Maximum = max(_Maximum, pages.Y);

		adjMatrix[pages.X - 1][pages.Y - 1] = 1;
		while (cin >> pages.X >> pages.Y && (pages.X && pages.Y))
		{
			adjMatrix[pages.X - 1][pages.Y - 1] = 1;
			_Maximum = max(_Maximum, pages.X);
			_Maximum = max(_Maximum, pages.Y);
		}
		
		For (k, 0, _Maximum + 1) For (i, 0, _Maximum + 1) For (j, 0, _Maximum + 1)
			adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);

		For (i, 0, _Maximum + 1) For (j, 0, _Maximum + 1)
		{
			if (i != j) if (adjMatrix[i][j] != 100000)
			{
				sum += adjMatrix[i][j];
				counter++;
			}
		}
		average = sum / counter;

		cout << "Case " << cases << ": average length between pages = " 
			 << fixed << setprecision(3) << average << " clicks" << endl;
	}
	return 0;
}