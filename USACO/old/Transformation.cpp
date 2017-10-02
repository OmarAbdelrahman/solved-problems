/*
ID: 1010
PROG: transform
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
//#define					   cin									fin
//#define					  cout								   fout

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;	
typedef            long double							LongDouble;

using namespace std;

int N;
int sz;
vector<string> _before_transformation;
vector<string> _after_transformation;

bool NintyDegree();
bool HundredEightyDegree();
bool TwoHundredSeventyDegree();
bool Reflection();
bool Combination();
bool NoChange();
bool ReflectionPlusNinty();
bool ReflectionPlusOneEighty();
bool ReflectionPlusTwoSeventy();

int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	cin >> N;
	_before_transformation.resize(N);
	_after_transformation.resize(N);
	sz = N - 1;
	for (int i = 0; i < size(_before_transformation); i++)
		cin >> _before_transformation[i];
	for (int i = 0; i < size(_after_transformation); i++)
		cin >> _after_transformation[i];
	if (NintyDegree()) cout << N << endl;
	else if (HundredEightyDegree()) cout << N << endl;
	else if (TwoHundredSeventyDegree()) cout << N << endl;
	else if (Reflection()) cout << N << endl;
	else if (Combination()) cout << N << endl;
	else if (NoChange()) cout << N << endl;
	else cout << "7" << endl;
	return 0;
}

bool NintyDegree()
{
	for (int i = 0; i < size(_before_transformation); i++)
		for (int j = 0; j < size(_before_transformation); j++)
			if (_before_transformation[i][j] != _after_transformation[j][sz - i])
				return false;
	N = 1; return true;
}

bool HundredEightyDegree()
{
	for (int i = 0; i < size(_before_transformation); i++)
		for (int j = 0; j < size(_before_transformation); j++)
			if (_before_transformation[i][j] != _after_transformation[sz - i][sz - j])
				return false;
	N = 2; return true;
}

bool TwoHundredSeventyDegree()
{
	for (int i = 0; i < size(_before_transformation); i++)
		for (int j = 0; j < size(_before_transformation); j++)
			if (_before_transformation[i][j] != _after_transformation[sz - j][i])
				return false;
	N = 3; return true;
}

bool Reflection()
{
	for (int i = 0; i < size(_before_transformation); i++)
		for (int j = 0; j < size(_before_transformation) / 2; j++)
			if (_before_transformation[i][j] != _after_transformation[i][sz - j])
				return false;
	if (N % 2)
	{
		for (int i = 0; i < size(_before_transformation); i++)
			if (_before_transformation[i][N / 2] != _after_transformation[i][N / 2])
				return false;
	}
	N = 4; return true;
}

bool ReflectionPlusNinty()
{
	for (int i = 0; i < size(_before_transformation); i++)
		for (int j = 0; j < size(_before_transformation); j++)
			if (_before_transformation[i][j] != _after_transformation[sz - j][sz - i])
				return false;
	return true;
}

bool ReflectionPlusOneEighty()
{
	for (int i = 0; i < size(_before_transformation); i++)
		for (int j = 0; j < size(_before_transformation); j++)
			if (_before_transformation[i][j] != _after_transformation[sz - i][j])
				return false;
	return true;
}

bool ReflectionPlusTwoSeventy()
{
	for (int i = 0; i < size(_before_transformation); i++)
		for (int j = 0; j < size(_before_transformation); j++)
			if (_before_transformation[i][j] != _after_transformation[j][i])
				return false;
	return true;
}

bool Combination()
{
	if (ReflectionPlusNinty() || ReflectionPlusOneEighty() || ReflectionPlusTwoSeventy())
	{
		N = 5;
		return true;
	}
	return false;
}

bool NoChange()
{
	for (int i = 0; i < size(_before_transformation); i++)
		if (_before_transformation[i] != _after_transformation[i])
			return false;
	N = 6; return true;
}