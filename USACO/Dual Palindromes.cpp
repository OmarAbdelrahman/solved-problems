/*
ID: 1010
PROG: dualpal
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

bool IsPalindrome(string& p_number)
{
	if (p_number[0] == '0' && p_number[size(p_number) - 1] == '0')
		return false;
	string temp = p_number;
	reverse(All(temp));
	return (temp == p_number);
}

string Convert(int p_number, int& p_base)
{
	string result = "";
	while (p_number)
	{
		result += (p_number % p_base > 9) ? (((p_number % p_base) + '0') - '9' + 'A' - 1) : (p_number % p_base) + '0';
		p_number /= p_base;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	int N, S;
	string tocheck;
	int counter;

	cin >> N >> S;
	for (int i = 0; i < N;)
	{
		counter = 0, S++;
		for (int j = 2; j <= 10; j++)
		{
			tocheck = Convert(S, j);
			if (IsPalindrome(tocheck))
				counter++;
			if (counter == 2)
			{
				cout << S << endl;
				i++;
				break;
			}
		}
	}
	return 0;
}