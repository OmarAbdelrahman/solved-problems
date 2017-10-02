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

#define                size(A)					    ((int)A.size())
#define                 All(A)					 A.begin(), A.end()
#define          For(i, Limit)		for (int i = 0; i < Limit; i++)
#define                    MAX									 30

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;	
typedef            long double							LongDouble;

using namespace std;

template <class _Ty>
class Queue: public queue <_Ty>
{
public:
	_Ty Dequeue()
	{
		_Ty tmp = queue <_Ty>::front();
		queue <_Ty>::pop();
		return tmp;
	}
};

int main()
{
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

	int numberOfFarmers;
	int maximum, minimum;
	int startTime, endTime;
	bool periodTaken[1000000] = {false};

	minimum = 10000001;
	maximum = -10000001;

	int MaxCont = 0;
	int MaxIdle = 0;

	int Idle = 0;
	int Continous = 0;

	cin >> numberOfFarmers;
	for (int i = 0; i < numberOfFarmers; i++)
	{
		cin >> startTime >> endTime;
		minimum = min(startTime, minimum);
		maximum = max(endTime, maximum);
		for (int j = startTime; j < endTime; j++)
			periodTaken[j] = true;
	}
	
	for (int i = minimum; i < maximum; i++)
	{
		if (periodTaken[i])
		{
			Continous++;
			Idle = 0;
		}
		else
		{
			Idle++;
			Continous = 0;
		}
		MaxCont = max(Continous, MaxCont);
		MaxIdle = max(Idle, MaxIdle);
	}
	cout << MaxCont << ' ' << MaxIdle << endl;

	return 0;
}