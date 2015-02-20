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

bool prime[2005];

void GeneratePrimes() {
	memset(prime, true, sizeof(prime)); prime[1] = false;
	for (int i = 2; i < sqrt(2004.); i++) if (prime[i])
		for (int j = i * i; j < 2004; j += i) prime[j] = false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
#endif
	int cases;
	string in;
	GeneratePrimes();
	scanf("%d", &cases);
	for (int turn = 1; cases--; turn++) {
		cin >> in;
		set <char> s;
		for (string::size_type i = 0; i < in.size(); i++) {
			if (binary_search(all(s), in[i]))
				continue;
			int c = count(all(in), in[i]);
			if (prime[c]) s.insert(in[i]);
		}
		printf("Case %d: ", turn);
		if (s.size() == 0) {
			puts("empty");
			continue;
		}
		for (set <char>::iterator it = s.begin(); it != s.end(); it++)
			cout << *it;
		cout << endl;
	}

	return 0;
}