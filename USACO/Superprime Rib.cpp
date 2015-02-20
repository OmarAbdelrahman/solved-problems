/*
ID: 1010
PROG: sprime
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int len, s = 0, e;
vector<int> ribs;

bool prime(int n)
{
	if (n == 2) return 1;
	if (!(n % 2) || n == 1) return 0;
	for (int i = 3; i <= sqrt(n * 1.); i += 2)
		if (!(n % i)) return 0;
	return 1;
}

inline void fill(int i)
{
	for (int j = 1; j < 10; j += 2)
	{
		int n = ribs[i] * 10 + j;
		if (prime(n)) ribs.push_back(n);
	}
}

inline void _1()
{
	ribs.push_back(2);
	ribs.push_back(3);
	ribs.push_back(5);
	ribs.push_back(7);
	e = (int)ribs.size();
}

inline void _2()
{
	for (int i = s; i < e; ++i)
		fill(i);
	s = e, e = (int)ribs.size();
}

inline void _3()
{
	for (int i = s; i < e; ++i)
		fill(i);
	s = e, e = (int)ribs.size();
}

inline void _4()
{
	for (int i = s; i < e; ++i)
		fill(i);
	s = e, e = (int)ribs.size();
}

inline void _5()
{
	for (int i = s; i < e; ++i)
		fill(i);
	s = e, e = (int)ribs.size();
}

inline void _6()
{
	for (int i = s; i < e; ++i)
		fill(i);
	s = e, e = (int)ribs.size();
}

inline void _7()
{
	for (int i = s; i < e; ++i)
		fill(i);
	s = e, e = (int)ribs.size();
}

inline void _8()
{
	for (int i = s; i < e; ++i)
		fill(i);
	s = e, e = (int)ribs.size();
}

inline int count(int n)
{
	int c = 0;
	while (n) ++c, n /= 10;
	return c;
}

int main()
{
	_1(), _2(), _3(), _4();
	_5(), _6(), _7(), _8();
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	scanf("%d", &len);
	for (int i = 0; i < (int)ribs.size(); ++i)
	{
		int m = count(ribs[i]);
		if (m == len) printf("%d\n", ribs[i]);
		else if (m > len) break;
	}
	return 0;
}