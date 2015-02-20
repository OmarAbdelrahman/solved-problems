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
#define all(A) A.begin(), A.end()
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

struct Matrix
{
	i64 n11, n12;
	i64 n21, n22;
	Matrix() { }
	Matrix(i64 _11, i64 _12, i64 _21, i64 _22)
	{
		n11 = _11, n12 = _12;
		n21 = _21, n22 = _22;
	}
	void operator = (Matrix m)
	{
		n11 = m.n11;
		n12 = m.n12;
		n21 = m.n21;
		n22 = m.n22;
	}
};

Matrix multiply(Matrix& t, Matrix& m, int& mod)
{
	Matrix toret;
	toret.n11 = ((t.n11 * m.n11)) % mod + ((t.n12 * m.n21)) % mod;
	toret.n12 = ((t.n11 * m.n12)) % mod + ((t.n12 * m.n22)) % mod;
	toret.n21 = ((t.n21 * m.n11)) % mod + ((t.n22 * m.n21)) % mod;
	toret.n22 = ((t.n21 * m.n12)) % mod + ((t.n22 * m.n22)) % mod;
	toret.n11 %= mod;
	toret.n12 %= mod;
	toret.n21 %= mod;
	toret.n22 %= mod;
	return toret;
}

Matrix Power(Matrix base, int power, int& mod)
{
	Matrix result(1, 1, 1, 0);
	while (power != 1)
	{
		if (power % 2)
		{
			--power;
			result = multiply(result, base, mod);
		}
		else
		{
			power >>= 1;
			base = multiply(base, base, mod);
		}
	}
	return multiply(result, base, mod);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.in", "rt", stdin);
#endif
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (!n) { puts("0"); continue; }
		if (n == 1 && !m) { puts("1"); continue; }
		m = (1 << m);
		Matrix fibo = Power(Matrix(1, 1, 1, 0), n, m);
		cout << fibo.n22 << endl;
	}
	return 0;
}
