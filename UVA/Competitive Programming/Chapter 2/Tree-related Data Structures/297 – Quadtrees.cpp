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

int const MAXN = 32;
int const BLACK = 1;
int const WHITE = 0;

struct io {
	template<class T> static T next() {
		T n; std::cin >> n;
		return n;
	}
};

static void initialize_all(int A[][MAXN], int B[][MAXN]) {
	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);
}

static void create_image(int& ptr, int x, int y, int size, string s, int M[][MAXN]) {
	if (ptr >= s.length())
		return;
	if (s[ptr] == 'p') {
		ptr++;
		create_image(ptr, x, y, size / 2, s, M);
		create_image(ptr, x + size / 2, y, size / 2, s, M);
		create_image(ptr, x, y + size / 2, size / 2, s, M);
		create_image(ptr, x + size / 2, y + size / 2, size / 2, s, M);
	} else {
		for (int i = x; i < x + size; ++i)
			for (int j = y; j < y + size; ++j)
				M[i][j] = s[ptr] == 'e' ? WHITE : BLACK;
		ptr++;
	}
}

int main(int argc, char **args) {
	int TC = io::next<int>();
	int A[MAXN][MAXN];
	int B[MAXN][MAXN];
	while (TC-- > 0) {
		string a = io::next<string>();
		string b = io::next<string>();
		initialize_all(A, B);
		int ptr = 0;
		create_image(ptr, 0, 0, MAXN, a, A);
		create_image((ptr = 0), 0, 0, MAXN, b, B);
		int result = 0;
		for (int i = 0; i < MAXN; ++i)
			for (int j = 0; j < MAXN; ++j)
				result += (int) (A[i][j] == BLACK || B[i][j] == BLACK);
		printf("There are %d black pixels.\n", result);
	}
	return 0;
}