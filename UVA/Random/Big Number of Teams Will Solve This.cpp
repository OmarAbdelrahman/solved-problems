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

bool _Compare(string& ans, string& compare)
{
	string cmp;

	for (int i = 0; i < sz(ans); i++)
		if (ans[i] != ' ') cmp += ans[i];

	return (cmp == compare);
}

int main() 
{
	int cases;
	scanf("%d", &cases);

	string answer;
	string tocompare;

	cin.ignore();
	for (int c = 1; cases--; c++)
	{
		getline(cin, answer);
		getline(cin, tocompare);

		if (answer == tocompare)
			cout << "Case " << c << ": " << "Yes" << endl;
		else if (sz(answer) == sz(tocompare))
			cout << "Case " << c << ": " << "Wrong Answer" << endl;
		else if (_Compare(answer, tocompare))
			cout << "Case " << c << ": " << "Output Format Error" << endl;
		else
			cout << "Case " << c << ": " << "Wrong Answer" << endl;
	}

	return 0;
}