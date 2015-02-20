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

typedef unsigned long long int64;

const int MAX = 10000010;

int size = 0;
int primes[MAX];
bool is_prime[MAX];

inline static void fill_prime() {
	memset(is_prime, true, sizeof is_prime);
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i << 1 < MAX; ++i)
		if (is_prime[i]) {
			for (int j = i << 1; j < MAX; j += i)
				is_prime[j] = false;
		}

	for (int i = 0; i < MAX; ++i)
		if (is_prime[i])
			primes[size++] = i;
}

int main(int argc, char **args) {
	fill_prime();
	for (int n; cin >> n && n > 0; ) {
		bool found = false;
		for (int i = 0; i < size && primes[i] < n && !found; ++i) {
			const int& p1 = primes[i];
			if (p1 & 1) {
				const int p2 = n - p1;
				if (is_prime[p2] && (p2 & 1)) {
					cout << n << " = " << p1 << " + " << p2 << endl;
					found = true;
				}
			}
		}
		if (!found) cout << "Goldbach's conjecture is wrong." << endl;
	}
	return 0;
}