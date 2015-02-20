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

VI first, second;
int firstSize, secondSize;
int lcs[105][105];

int NumberofTiles()
{
	For (i, 0, sz(first) + 1)
	{
		For (j, 0, sz(second) + 1)
		{
			if (!i || !j)
				lcs[i][j] = 0;
			else if (first[i - 1] == second[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	return lcs[sz(first)][sz(second)];
}

int main() 
{
	for (int towerNumber = 1; cin >> firstSize >> secondSize && (firstSize != 0 && secondSize != 0); towerNumber++)
	{
		res(first, firstSize);
		res(second, secondSize);

		For (i, 0, sz(first)) cin >> first[i];
		For (i, 0, sz(second)) cin >> second[i];

		printf("Twin Towers #%d\n", towerNumber);
		printf("Number of Tiles : %d\n\n", NumberofTiles());
	}
	return 0;
}