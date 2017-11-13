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

const int BIG_NUM = 1000000000;

struct io {
	template<class T> static inline T next() {
		T x; std::cin >> x;
		return x;
	}
};

int main(int argc, char **args) {
	vector<vector<int>> g(100, vector<int>(100));
	for (int C = 1;; ++C) {
		int a = io::next<int>();
		int b = io::next<int>();
		if (a == 0 && b == 0)
			break;
		for (int i = 0; i < g.size(); ++i)
			fill(g[i].begin(), g[i].end(), BIG_NUM);
		g[a - 1][b - 1] = 1;
		int n = max(a, b);
		while (true) {
			a = io::next<int>();
			b = io::next<int>();
			if (a == 0 && b == 0)
				break;
			g[a - 1][b - 1] = 1;
			n = max(n, max(a, b));
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		double count = 0;
		double result = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i != j && g[i][j] < BIG_NUM) {
					result += g[i][j];
					count++;
				}
		printf("Case %d: average length between pages = %.3lf clicks\n", C, result / count);
	}
	return 0;
}