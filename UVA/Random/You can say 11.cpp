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
#define                    MAX									 31

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;	
typedef            long double							LongDouble;

using namespace std;

int main()
{
	ULongInt num;
	string number;
	LongInt even, odd;

	while (cin >> number && number != "0")
	{
		if (size(number) <= 19)
		{
			stringstream ss(number);
			ss >> num;
			(!(num % 11)) ?	cout << num << " is a multiple of 11." << endl :
							cout << num << " is not a multiple of 11." << endl;
			continue;
		}

		even = odd = 0;

		For (i, 0, size(number))
			(i % 2) ? even += number[i] - '0' : odd += number[i] - '0';
		
		(!((even - odd) % 11)) ? cout << number << " is a multiple of 11." << endl :
								 cout << number << " is not a multiple of 11." << endl;
	}

	return 0;
}