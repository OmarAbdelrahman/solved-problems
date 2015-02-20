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

int main()
{	
	int c, n;
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d", &n);
		LongInt N;
		N = n * 567;
		N /= 9;
		N += 7492;
		N *= 235;
		N /= 47;
		N -= 498;
		if (N < 0) N *= -1;
		int t = N % 10;
		N -= t;
		N /= 10;
		cout << N % 10 << endl;
	}
	return 0;
}