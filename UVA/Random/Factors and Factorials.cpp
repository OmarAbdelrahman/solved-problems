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

map <int, vector <int> > numberFactors; 

void GeneratePrimeFactors(int number)
{
	int n = number;
	while (!(number % 2))
	{
		numberFactors[n].push_back(2);
		number = number / 2;
	}
	for (int i = 3; i <= sqrt((double)number);)
	{
		if (!(number % i))
		{
			numberFactors[n].push_back(i);
			number = number / i;
			continue;
		}
		i = i + 2;
	}
	if (number > 1) numberFactors[n].push_back(number);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	for (int i = 2; i <= 100; i++) 
		GeneratePrimeFactors(i);
	
	int number;
	map <int, int> values;

	while (scanf("%d", &number) && (number))
	{
		for (int i = 2; i <= number; i++)
			for (size_t j = 0; j < numberFactors[i].size(); j++)
				++values[numberFactors[i][j]];
		cout << setw(3) << right << number << "! =";

		int length = 0;
		for (map <int, int>::iterator it = values.begin(); it != values.end(); it++)
		{
			cout << setw(3) << right << it->second;
			if (length == 14 && length != values.size() - 1)
				cout << endl << "      ";
			length++;
		}
		cout << endl;
		values.clear();
	}

	return 0;
}