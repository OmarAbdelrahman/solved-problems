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

vector<int> primes;
vector<int> primeCount(1005, 0);

void fill_prime() {
	vector<bool> is_prime(1005, true);
	is_prime[0] = false;
	is_prime[1] = false;
	primes.push_back(1);
	primeCount[1] = 1;
	for (int i = 2; i * i < is_prime.size(); ++i)
		if (is_prime[i]) {
			for (int j = i * i; j < is_prime.size(); j += i)
				is_prime[j] = false;
		}

	for (int i = 2; i < is_prime.size(); ++i) {
		primeCount[i] = primeCount[i - 1];
		if (is_prime[i]) {
			primes.push_back(i);
			primeCount[i]++;
		}
	}
}

int main(int argc, char **args) {
	fill_prime();
	for (int n, c; cin >> n >> c; ) {
		cout << n << " " << c << ":";

		const int& count = primeCount[n];
		const int middle = count >> 1;
		int rightIndex, leftIndex;

		if (count & 1) {
			leftIndex = max(0, middle - (c - 1));
			rightIndex = min(count - 1, middle + (c - 1));
		} else {
			rightIndex = min(count - 1, middle + c - 1);
			leftIndex = max(0, middle - c);
		}

		for (int i = leftIndex; i <= rightIndex; ++i)
			cout << " " << primes[i];

		cout << endl << endl;
	}
	return 0;
}