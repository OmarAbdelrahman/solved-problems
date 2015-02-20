#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
#include <fstream>
using namespace std;

const int MAXP = 20000000;
const int MAXI = 100002;

int size = 1;
bool isPrime[MAXP];
pair<int, int> p[MAXI];

inline static void fill_prime() {
	memset(isPrime, true, sizeof isPrime);
	isPrime[1] = false;
	for (int i = 2; i << 1 < MAXP; ++i)
		if (isPrime[i]) {
			for (int j = i << 1; j < MAXP; j += i)
				isPrime[j] = false;
		}

	for (int i = 3; i + 2 < MAXP; ++i)
		if (isPrime[i] && isPrime[i + 2])
			p[size++] = make_pair(i, i + 2);
}

int main(int argc, char **args) {
	fill_prime();
	for (int n; cin >> n; )
		cout << "(" << p[n].first << ", " << p[n].second << ")" << endl;
	return 0;
}