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

int LCS[10000][10000];
string first, second;

int LCSLength(int length1, int length2)
{
	for (int i = 0; i <= length1+1; i++)
		for (int j = 0; j <= length2+1; j++)
		{
			if (!i || !j)
				LCS[i][j] = 0;
			else if (first[i - 1] == second[j - 1])
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	return LCS[length1][length2];
}

int main()
{
	while (getline(cin,first))
	{
		getline(cin,second);
		cout << LCSLength(size(first), size(second)) << endl;
	}
	return 0;
}