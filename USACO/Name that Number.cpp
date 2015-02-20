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
#define					   cin									fin
#define					  cout								   fout

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;	
typedef            long double							LongDouble;

using namespace std;

string temp;
string number;
vector <string> listofName;

bool IsInList()
{
	for (int i = 0; i < size(number); i++)
	{
		switch (number[i])
		{
		case '2': 
			if (temp[i] != 'A' && temp[i] != 'B' && temp[i] != 'C')
				return false;
			break;
		case '3': 
			if (temp[i] != 'D' && temp[i] != 'E' && temp[i] != 'F')		  
				return false;
			break;
		case '4': 
			if (temp[i] != 'G' && temp[i] != 'H' && temp[i] != 'I')
				return false;
			break;
		case '5': 
			if (temp[i] != 'J' && temp[i] != 'K' && temp[i] != 'L')
				return false;
			break;
		case '6': 
			if (temp[i] != 'M' && temp[i] != 'N' && temp[i] != 'O')
				return false;
			break;
		case '7': 
			if (temp[i] != 'P' && temp[i] != 'R' && temp[i] != 'S')
				return false;
			break;
		case '8': 
			if (temp[i] != 'T' && temp[i] != 'U' && temp[i] != 'V')
				return false;
			break;
		case '9': 
			if (temp[i] != 'W' && temp[i] != 'X' && temp[i] != 'Y')
				return false;
			break;
		}
	}
	return true;
}

int main()
{
	ifstream in("dict.txt");
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");

	cin >> number;
	while (in >> temp)
		if (size(temp) == size(number))
			if (IsInList()) listofName.push_back(temp);
	
	if (size(listofName) == 0) 
	{
		cout << "NONE" << endl;
		return 0;
	}
	for (int i = 0; i < size(listofName); i++)
		cout << listofName[i] << endl;
	
	return 0;
}