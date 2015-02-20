#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

typedef long long i64;
const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

bool Prime(int n)
{
	for (int i = 3; i <= sqrt((double)n); i = i + 2)
		if (!(n % i)) return false;
	return true;
}

template <typename T> inline T square(T const& x)
{
	return x * x;
}

i64 BigMod(i64 B, i64 P, i64 M)
{
	if (!P) return 1;
	else if (!(P % 2)) return square(BigMod(B, P / 2, M)) % M;
	else return ((B % M) * BigMod(B, P - 1, M)) % M;
}

bool Carm(int n)
{
	for (int i = 2; i < n; i++)
		if (BigMod(i, n, n) != i)
			return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n) && (n))
	{
		if (!Prime(n) && Carm(n))
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
	}
	return 0;
}