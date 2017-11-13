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

double table[22][22][22];
int parent[22][22][22];

void initialize(const int& n) {
	memset(table, 0.0, sizeof table);
	memset(parent, -1, sizeof parent);
}

int main(int argc, char **args) {
	for (int n; cin >> n; ) {
		initialize(n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == j)
					table[0][i][j] = 1.0;
				else
					table[0][i][j] = io::next<double>();
				parent[0][i][j] = i;
			}

		for (int length = 1; length < n; ++length)
			for (int k = 0; k < n; ++k)
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j) {
						double value = table[length - 1][i][k] * table[0][k][j];
						if (value > table[length][i][j]) {
							table[length][i][j] = value;
							parent[length][i][j] = k;
						}
					}

		int resLen = -1;
		int index = -1;
		for (int length = 1; length < n; ++length) {
			for (int i = 0; i < n; ++i)
				if (table[length][i][i] > 1.01) {
					index = i;
					resLen = length;
					break;
				}
			if (index != -1) break;
		}

		if (index == -1)
			cout << "no arbitrage sequence exists" << endl;
		else {
			vector<int> path;
			path.push_back(index);
			int current = index;
			for (int length = resLen; length >= 0; --length) {
				current = parent[length][index][current];
				path.push_back(current);
			}
			cout << path[path.size() - 1] + 1;
			for (int i = path.size() - 2; i >= 0; --i)
				cout << " " << path[i] + 1;
			cout << endl;
		}
	}
	return 0;
}