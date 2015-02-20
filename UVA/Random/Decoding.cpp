/*
ID: 1010
PROG: namenum
LANG: C++
*/

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

#define                size(A)					    ((int)A.size())
#define                 All(A)					 A.begin(), A.end()
#define          For(i, Limit)		for (int i = 0; i < Limit; i++)
#define                    MAX									 30

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;	
typedef            long double							LongDouble;

using namespace std;

int main()
{
	string word;
	int numberofCases;
	int numberofRepitions;
	char character;

	scanf("%d", &numberofCases);
	for (int _Cases = 1; _Cases <= numberofCases; _Cases++)
	{
		cin >> word;
		stringstream streamin(word);

		cout << "Case " << _Cases << ": ";

		while (!streamin.eof())
		{
			streamin >> character;
			streamin >> numberofRepitions;
			for (int i = 0; i < numberofRepitions; i++)
				cout << character;
		}
		cout << endl;
	}
	return 0;
}