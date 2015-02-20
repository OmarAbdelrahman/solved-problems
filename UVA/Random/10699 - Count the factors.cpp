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

struct io {
	template<class T> static inline T next() {
		T x; std::cin>> x;
		return x;
	}
};

static int getCnt(int n) {
	set<int> factors;
	while (n % 2 == 0) {
		factors.insert(2);
		n >>= 1;
	}
	for (int i = 3; i * i <= n; ) {
		if (n % i == 0) {
			factors.insert(i);
			n /= i;
			continue;
		}
		i += 2;
	}
	if (n > 1) factors.insert(n);
	return factors.size();
}

int main(int argc, char **args) {
	while (true) {
		int n = io::next<int>();
		if (!n) break;
		cout << n << " : " << getCnt(n) << endl;
	}
	return 0;
}