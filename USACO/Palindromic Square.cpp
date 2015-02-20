/*
ID: 1010
PROG: palsquare
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

#define sz(A) ((int)A.size())
#define All(A) A.begin(), A.end()

using namespace std;

bool IsPalindrome(string number)
{
	string temp = number;
	reverse(All(temp));
	return temp == number;
}

string GetBase(int number, int base)
{
	string res;
	while (number)
	{
		res += ((number % base) + '0') > '9' ? ((number % base) + '0') - '9' + 'A' - 1 : ((number % base) + '0');
		number /= base;
	}
	reverse(All(res));
	return res;
}

int main()
{
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	int base;
	string number, square;
	cin >> base;
	for (int i = 1; i <= 300; i++)
	{
		number = GetBase(i, base);
		square = GetBase(i * i, base);
		if (IsPalindrome(square))
			cout << number << ' ' << square << endl;
	}
	return 0;
}