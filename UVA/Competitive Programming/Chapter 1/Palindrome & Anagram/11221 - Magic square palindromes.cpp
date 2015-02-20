#include <assert.h>
#include <ctype.h>
#include <cmath>
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
#include <cstdio>
#include <limits>
using namespace std;

const char SPACE = ' ';
const int N = 100;

struct io {
	template<class T> static inline T next() {
		T x; std::cin >> x;
		return x;
	}

	static inline std::string next_line(bool ignore = true) {
		if (ignore) std::cin.ignore();
		std::string s; std::getline(std::cin, s);
		return s;
	}
};

static void purify_sentence(string& str) {
	for (int i = 0; i < str.length(); ++i)
		if (!isalpha(str[i]))
			str.erase(str.begin() + i--);
}

static bool is_square(const int n) {
	const int root = (int) sqrt(n);
	return root * root == n;
}

static bool is_magic(const string& s, char grid[][N]) {
	const int power = (int) sqrt(s.length());

	int index = 0;
		for (int i = 0; i < power; ++i)
			for (int j = 0; j < power; ++j)
				grid[i][j] = s[index++];

	index = 0;
	for (int a1 = 0, a2 = power - 1; a1 < power; ++a1, --a2)
		for (int b1 = 0, b2 = power - 1; b1 < power; ++b1, --b2) {
			const char ch = s[index++];
			if (grid[a1][b1] != ch || grid[b1][a1] != ch || grid[a2][b2] != ch || grid[b2][a2] != ch)
				return false;
		}

	return true;
}

int main(int argc, char** args) {
	int T = io::next<int>();
	cin.ignore();

	char grid[N][N];
	for (int t = 1; T-- > 0; ++t) {
		string sentence = io::next_line(false);
		purify_sentence(sentence);
		
		const int n = sentence.length();

		cout << "Case #" << t << ":" << endl;
		if (is_square(n) && is_magic(sentence, grid))
			cout << (int) sqrt(n) << endl;
		else
			cout << "No magic :(" << endl;
	}
  return 0;
}