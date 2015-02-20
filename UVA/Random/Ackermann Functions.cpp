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

template <class _Ty>
class Queue: public queue <_Ty> {
	public:
		_Ty Dequeue() {
			_Ty tmp = queue <_Ty>::front();
			queue <_Ty>::pop();
			return tmp;
		}
};

longint _Maximum;
longint first, second;
longint firstLongest;
longint temp;

longint collatz(longint n, longint counter)
{
	if (n == 1)
		return counter;
	if (!(n % 2))
		return collatz(n / 2, counter += 1);
	else
		return collatz((3 * n) + 1, counter += 1);
}

int main() 
{
	while (cin >> first >> second && (first && second))
	{
		_Maximum = 0;
		if (first > second)
			swap(first, second);

		if (first == second == 1)
		{
			puts("Between 1 and 1, 1 generates the longest sequence of 3 values.");
			continue;
		}

		for (longint i = first; i <= second; i++)
		{
			temp = collatz(i, 0);
			if (temp > _Maximum)
			{
				_Maximum = temp;
				firstLongest = i;
			}
		}

		cout << "Between " << first << " and " << second << ", "
			 << firstLongest << " generates the longest sequence of " 
			 << _Maximum << " values.\n";
	}
	return 0;
}