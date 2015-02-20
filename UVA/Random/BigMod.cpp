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

template <typename T> inline T square(T const& x)
{
	return x * x;
}

long BigMod(long B, long P, long M)
{
	if (!P) return 1;
	else if (!(P % 2)) return square(BigMod(B, P / 2, M)) % M;
	else return ((B % M) * BigMod(B, P - 1, M)) % M;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	unsigned int B, P, M;
	while (cin >> B >> P >> M)
		cout << BigMod(B, P, M) << endl;
	return 0;
}