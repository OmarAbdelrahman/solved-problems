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
#include "iomanip"
#include "iostream"
using namespace std;

typedef long long i64;
const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int arr[1000002] = {0};

int GenerateFactors(int number)
{
	int counter = 0;
	while (!(number % 2))
	{
		++counter;
		number >>= 1;
	}
	for (int i = 3; i <= sqrt((double)number);)
	{
		if (!(number % i))
		{
			++counter;
			number /= i;
			continue;
		}
		i = i + 2;
	}
	if (number > 1) ++counter;
	return counter;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif

	arr[2] = 1;
	for (int i = 3; i <= 1000000; i++)
		arr[i] = arr[i - 1] + GenerateFactors(i);

	for (int number = 0; cin >> number;)
		cout << arr[number] << endl;

	return 0;
}
