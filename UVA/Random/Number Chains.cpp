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

longint asc, counter;
longint decs;
string descending;
string lastValue, result;
set <string> searching;
set <string>::iterator it;

inline string GetDifference(string n)
{
	sort(All(n));
	descending = n;
	reverse(All(descending));

	n += " ";
	n += descending;

	stringstream sin(n);
	sin >> asc >> decs;

	cout << decs << " - " 
		 << asc  << " = " 
		 << decs - asc << endl;

	stringstream ss;
	ss << (decs - asc);

	return ss.str();
}

longint GetChainLength(string n)
{
	counter = 0;
	result = GetDifference(n);
	searching.insert(result);

	while (++counter)
	{
		result = GetDifference(result);
		it = searching.find(result);
		if (it != searching.end())
			break;
		searching.insert(result);
	}
	return counter;
}

int main() 
{
	string number;
	while (cin >> number && number != "0")
	{
		cout << "Original number was " << number << endl;
		cout << "Chain length " << GetChainLength(number) + 1 << endl << endl;
		c(searching);
	}
	return 0;
}