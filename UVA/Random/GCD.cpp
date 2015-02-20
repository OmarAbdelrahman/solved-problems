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

int gcd(int a, int b)
{
	if (!b) return a;
	else return gcd(b, a % b);
}

int main()
{	
	int n, s;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		s = 0;
		For (i, 1, n)
			For (j, i + 1, n + 1)
				s += gcd(i, j);

		cout << s << endl;
	}
	return 0;
}