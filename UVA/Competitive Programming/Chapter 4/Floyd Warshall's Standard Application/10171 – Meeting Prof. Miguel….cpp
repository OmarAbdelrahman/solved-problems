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

void add(const int& a, const int& b, const int& c, const char& dir, int g[][26]) {
	g[a][b] = min(g[a][b], c);
	if (dir == 'B')
		g[b][a] = min(g[b][a], c);
}

int main(int argc, char **args) {
	int g1[26][26];
	int g2[26][26];
	int value[26];
	for (int roads = io::next<int>(); roads > 0; roads = io::next<int>()) {
		for (int i = 0; i < 26; ++i) {
			fill(g1[i], g1[i] + 26, BIG_NUM);
			fill(g2[i], g2[i] + 26, BIG_NUM);
			g1[i][i] = g2[i][i] = 0;
		}
		for (int i = 0; i < roads; ++i) {
			char age = io::next<char>();
			char dir = io::next<char>();
			int a = io::next<char>() - 'A';
			int b = io::next<char>() - 'A';
			int c = io::next<int>();
			if (age == 'Y')
				add(a, b, c, dir, g1);
			else
				add(a, b, c, dir, g2);
		}
		for (int k = 0; k < 26; ++k)
			for (int i = 0; i < 26; ++i)
				for (int j = 0; j < 26; ++j) {
					g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
					g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);
				}
		int boy = io::next<char>() - 'A';
		int old = io::next<char>() - 'A';
		fill(value, value + 26, BIG_NUM);
		for (int i = 0; i < 26; ++i)
			value[i] = min(value[i], g1[boy][i] + g2[old][i]);
		int res = *min_element(value, value + 26);
		if (res >= BIG_NUM) {
			cout << "You will never meet." << endl;
			continue;
		}
		cout << res;
		for (int i = 0; i < 26; ++i)
			if (value[i] == res)
				cout << " " << (char) (i + 'A');
		cout << endl;
	}
	return 0;
}