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

template <class _Ty>
class Queue: public queue <_Ty> {
	public:
		_Ty Dequeue() {
			_Ty tmp = queue <_Ty>::front();
			queue <_Ty>::pop();
			return tmp;
		}
};

ULongInt arr[210000002];

int main()
{
	arr[0] = 1, arr[1] = 2, arr[2] = 4;
	for (int i = 3; i <= 210000000; i++)
		arr[i] = arr[i - 1] + i;

	int n;
	while (cin >> n && n >= 0)
		cout << arr[n] << endl;

	return 0;
}