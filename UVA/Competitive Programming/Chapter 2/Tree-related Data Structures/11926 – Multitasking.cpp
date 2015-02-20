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

struct io {
	template<class T> static T next() {
		T n; std::cin >> n;
		return n;
	}
};

bool task[1000001];

static bool doit(int a, int b) {
	for (int i = a; i <= b; ++i) {
		if (task[i]) return false;
		task[i] = true;
	}
	return true;
}

int main(int argc, char **args) {
	while (true) {
		memset(task, false, sizeof task);
		int n = io::next<int>();
		int m = io::next<int>();
		if (n == 0 && m == 0)
			break;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			int a = io::next<int>();
			int b = io::next<int>();
			if (ok)
				ok = doit(a + 1, b);
		}
		for (int i = 0; i < m; ++i) {
			int a = io::next<int>();
			int b = io::next<int>();
			int c = io::next<int>();
			if (ok) {
				while (a < 1000001 && ok) {
					ok = doit(a + 1, min(b, 1000000));
					a += c;
					b += c;
				}
			}
		}
		if (ok) puts("NO CONFLICT"); else puts("CONFLICT");
	}
	return 0;
}