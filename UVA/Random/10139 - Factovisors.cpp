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

map<int, int> pFact;

static void primeFactors(int n) {
	while (n % 2 == 0) {
		pFact[2]++;
		n >>= 1;
	}
	for (int i = 3; i * i <= n; ) {
		if (n % i == 0) {
			pFact[i]++;
			n /= i;
			continue;
		}
		i = i + 2;
	}
	if (n > 1) pFact[n]++;
}

int primePowInFact(int fact, int prime) {
	int result = 0;
	while (fact > 0) {
		result += fact / prime;
		fact /= prime;
	}
	return result;
}

int main(int argc, char **args) {
	for (int n, m; cin >> n >> m; pFact.clear()) {
		if (n >= m) {
			cout << m << " divides " << n << "!" << endl;
			continue;
		}
		if (m == 0) {
			cout << m << " does not divide " << n << "!" << endl;
			continue;
		}

		primeFactors(m);

		bool divides = true;
		for (map<int, int>::iterator it = pFact.begin(); it != pFact.end() && divides; ++it) {
			const int prime = it->first;
			const int power = it->second;

			const int prPower = primePowInFact(n, prime);
			if (prPower < power) divides = false;
		}

		cout << m << (divides ? " divides " : " does not divide ") << n << "!" << endl;
	}
	return 0;
}