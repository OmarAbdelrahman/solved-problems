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
	for (int TC = io::next<int>(), C = 1; TC-- > 0; ++C) {
		int buildings = io::next<int>();
		int roads = io::next<int>();
		vector<vector<int>> g(buildings, vector<int>(buildings, BIG_NUM));
		for (int i = 0; i < buildings; ++i) 
			g[i][i] = 0;
		while (roads-- > 0) {
			int a = io::next<int>();
			int b = io::next<int>();
			g[a][b] = g[b][a] = 1;
		}
		for (int k = 0; k < buildings; ++k)
			for (int i = 0; i < buildings; ++i)
				for (int j = 0; j < buildings; ++j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		int src = io::next<int>();
		int trg = io::next<int>();
		int result = -BIG_NUM;
		for (int i = 0; i < buildings; ++i)
			result = max(result, g[src][i] + g[i][trg]);
		cout << "Case " << C << ": " << result << endl;
	}
	return 0;
}