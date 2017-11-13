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
	template<typename T> static inline T next() {
		T x; std::cin>> x;
		return x;
	}

	static inline void read_file(const char* s) {
#ifndef ONLINE_JUDGE
		freopen(s, "r", stdin);
#endif
	}
};

const int A = 0;
const int B = 1;
const int C = 2;

deque<int> pegs[3];

void printSolution() {
	for (int i = 0; i < 3; ++i) {
		cout << (char) ('A' + i) << "=>";

		if (pegs[i].size() > 0) {
			cout << "  ";
			for (int j = 0; j < pegs[i].size(); ++j)
				cout << " " << pegs[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void hanoi(const int& from, const int& middle, const int& to, int n, int& m) {
	if (n > 0) {
		hanoi(from, to, middle, n - 1, m);

		pegs[to].push_back(pegs[from].back());
		pegs[from].pop_back();

		if (m-- > 0)
			printSolution();
		else
			return;

		hanoi(middle, from, to, n - 1, m);
	}
}

int main(int argc, char **args) {
	io::read_file("in.txt");
	for (int P = 1; ; ++P) {
		int n = io::next<int>();
		int m = io::next<int>();

		if (n == 0 && m == 0)
			break;

		cout << "Problem #" << P << endl;
		cout << endl;

		for (int i = 0; i < 3; ++i)
			pegs[i].clear();

		for (int i = 0; i < n; ++i)
			pegs[A].push_back(n - i);

		printSolution();
		hanoi(A, B, C, n, m);
	}
	return 0;
}