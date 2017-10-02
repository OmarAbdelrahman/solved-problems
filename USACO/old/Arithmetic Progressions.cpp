/*
ID: 1010
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;

int const max_t = 125001;
bool bisquares[max_t];
int const max_s = 10001;
pair<int, int> seq[max_s];
int m;

bool check(int b, int a, int length)
{
	for (int n = length - 1, m = 0; m <= length / 2; --n, ++m)
		if (bisquares[a + (n * b)] == 0 || bisquares[a + (m * b)] == 0)
			return false;
	return true;
}

int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	int len, lim;
	scanf("%d%d", &len, &lim);
	m = lim * lim * 2;
	for (int p = 0; p <= lim; ++p)
		for (int q = p; q <= lim; ++q)
			bisquares[p * p + q * q] = true;
	int index = 0;
	for (int b = 1; b <= m; ++b)
		for (int a = 0; a <= m; ++a)
		{
			if (a + ((len - 1) * b) > m)
				break;
			if (bisquares[a] == 0 || bisquares[a + b] == 0)
				continue;
			if (check(b, a, len)) 
				printf("%d %d\n", a, b), ++index;
		}
	if (!index) puts("NONE");
	return 0;
}