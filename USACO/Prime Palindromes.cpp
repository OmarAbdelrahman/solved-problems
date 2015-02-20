/*
ID: 1010
PROG: pprime
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

int a, b;

inline bool prime(int n)
{
	if (n == 2) return 1;
	if (!(n % 2) || n == 1) return 0;
	for (int i = 3; i <= sqrt((double)n); i += 2)
		if (!(n % i)) return 0;
	return 1;
}

inline bool ok(int& n)
{
	return n >= a && n <= b;
}

inline void _1()
{
	for (int i = 5; i < 10; i += 2)
		if (ok(i) && prime(i))
			printf("%d\n", i);
}

inline void _2()
{
	for (int i = 1; i < 10; i += 2)
	{
		int p = i * 10 + i;
		if (ok(p) && prime(p))
			printf("%d\n", p);
	}
}

inline void _3()
{
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; ++j)
		{
			int p = 100 * i + 10 * j + i;
			if (ok(p) && prime(p))
				printf("%d\n", p);
		}
}

inline void _4()
{
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; ++j)
		{
			int p = 1000 * i + 100 * j + 10 * j + i;
			if (ok(p) && prime(p))
				printf("%d\n", p);
		}
}

inline void _5()
{
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
			{
				int p = 10000 * i + 1000 * j + 100 * k + 10 * j + i;
				if (ok(p) && prime(p))
					printf("%d\n", p);
			}
}

inline void _6()
{
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
			{
				int p = 100000 * i + 10000 * j + 1000 * k + 100 * k + 10 * j + i;
				if (ok(p) && prime(p))
					printf("%d\n", p);
			}
}

inline void _7()
{
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				for (int l = 0; l < 10; ++l)
				{
					int p = 1000000 * i + 100000 * j + 10000 * k + 1000 * l + 100 * k + 10 * j + i;
					if (ok(p) && prime(p))
						printf("%d\n", p);
				}
}

inline void _8()
{
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				for (int l = 0; l < 10; ++l)
				{
					int p = 10000000 * i + 1000000 * j + 100000 * k + 10000 * l + 1000 * l + 100 * k + 10 * j + i;
					if (ok(p) && prime(p))
						printf("%d\n", p);
				}
}

int main()
{
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	scanf("%d%d", &a, &b);
	_1(), _2(), _3(), _4(), _5(), _6(), _7(), _8();
	return 0;
}