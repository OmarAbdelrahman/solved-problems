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
	while (true) {
		int col = io_utilis::next<int>();
		if (col == 0)
			break;
		string message = io_utilis::next<string>();
		int row = message.length() / col;
		vector<vector<char> > encrypted(row, vector<char>(col));
		int r = 0;
		int c = 0;
		for (int i = 0; i < message.length(); ++i) {
			encrypted[r][c++] = message[i];
			if (c == col)
				c = 0, r++;
		}
		for (int i = 1; i < row; i += 2)
			reverse(encrypted[i].begin(), encrypted[i].end());
		string result = "";
		for (int j = 0; j < col; ++j)
			for (int i = 0; i < row; ++i)
				result += encrypted[i][j];
		cout << result << endl;
	}
	return 0;
}