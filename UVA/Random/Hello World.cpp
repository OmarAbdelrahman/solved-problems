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

int main() {
	int n, s = 0;
	for (int c = 1; scanf("%d", &n) != EOF && n > -1; c++) {
		for (int i = 1; i < n; i *= 2) s++;
		printf("Case %d: %d\n", c, s); s = 0;
	}
	return 0;
}