/*
ID: 1010
PROG: milk2
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

#define                size(A)					((ULongInt)A.size())
#define                 All(A)					 A.begin(), A.end()
#define          For(i, Limit)		for (int i = 0; i < Limit; i++)
#define                    MAX									 30

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;	
typedef            long double							LongDouble;

using namespace std;

template <class _Ty>
_Ty Factorial(_Ty p_number)
{
	for (_Ty i = p_number - 1; i > 1; i--)
		p_number *= i;
	return p_number;
}

int main()
{	
	string word;
	ULongInt alphapet[26];
	ULongInt mainF;

	int numberOfCases;
	scanf("%d", &numberOfCases);
	for (int cases = 1; cases <= numberOfCases; cases++)
	{
		memset(alphapet, 0, sizeof(ULongInt) * 26);
		cin >> word;

		mainF = Factorial(size(word));
		for (int i = 0; i < size(word); i++)
			alphapet[word[i] - 'A']++;

		for (int i = 0; i < 26; i++)
			if (alphapet[i] > 1)
				mainF /= Factorial(alphapet[i]);

		cout << "Data set " << cases << ": " << mainF << endl;
	}
	return 0;
}