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

inline void GeneratePrimeFactors(int number, vector <int>& factors) {
	while (!(number % 2)) {
		factors.push_back(2);
		number /= 2;
	}
	for (int i = 3; i <= sqrt((double)number);) {
		if (!(number % i)) {
			factors.push_back(i);
			number /= i;
			continue;
		}
		i = i + 2;
	}
	if (number > 1) factors.push_back(number);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int number;
	vector <int> factors;
	while (cin >> number && number) {
		cout << number << " =";
		if (number < 0) {
			factors.push_back(-1);
			number = number * -1;
		}
		GeneratePrimeFactors(number, factors);
		for (size_t i = 0; i < factors.size(); i++)
			if (i == factors.size() - 1) {
				cout << ' ' << factors[i];
			} else {
				cout << ' ' << factors[i] << " x";
			}
		cout << endl;
		factors.clear();
	}
	return 0;
}