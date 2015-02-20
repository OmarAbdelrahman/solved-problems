/*
ID: 1010
PROG: fracdec
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <numeric>
#include <string.h>
#include <cstdio>
using namespace std;

#define sz(a) ((int)a.size())
#define maxT 100000 + 1

char ans[maxT];
int pos[maxT];

int main()
{
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	int left = n / d;
	int rem = n % d;
	cout << left << ".";
	int ptr = 0;
	do 
	{
		ptr++;
		left /= 10;
	} 
	while (left);
	int s = ++ptr;
	memset(pos, -1, sizeof(pos));
	while (pos[rem] == -1)
	{
		pos[rem] = ptr++;
		ans[pos[rem]] = rem * 10 / d + '0';
		rem = rem * 10 % d;
		if (!rem) break;
	}
	if (!rem)
	{
		for (int i = s; i < ptr; ++i)
		{
			cout << ans[i];
			if (i % 76 == 0) 
				cout << endl;
		}
	}
	else
	{
		int i;
		for (i = s; i < pos[rem]; ++i)
		{
			cout << ans[i];
			if (i % 76 == 0) 
				cout << endl;
		}
		cout << "(";
		if (++i % 76 == 0)
			cout << endl;
		for (; i < ptr + 1; ++i)
		{
			cout << ans[i - 1];
			if ((i + 1) % 76 == 0)
				cout << endl;
		}
		cout << ")";
	}
	cout << endl;
	return 0;
}