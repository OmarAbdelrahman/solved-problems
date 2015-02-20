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
using namespace std;

struct io_utilis {
	template<class T> static T next() {
		T n; std::cin >> n;
		return n;
	}
};

int main(int argc, char **args) {
	int TC = io_utilis::next<int>();
	while (TC-- > 0) {
		int index = io_utilis::next<int>();
		int n = 1, i, k;
		for (; index > (n * (n + 1)) >> 1; ++n);
		int v = (n * (n + 1)) >> 1;
		int s = ((n - 1) * n) >> 1;
		int a, b;
		if (n % 2 == 0) {
			a = 1, b = n;
			for (i = 0, k = s + 1; i < n && k != index; ++i, ++k)
				++a, --b;
		} else {
			a = n, b = 1;
			for (i = 0, k = s + 1; i < n && k != index; ++i, ++k)
				--a, ++b;
		}
		printf("TERM %d IS %d/%d\n", index, a, b);
	}
	return 0;
}