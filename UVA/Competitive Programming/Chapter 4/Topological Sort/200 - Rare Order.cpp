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

typedef long long int64;
#define LENGTH(s) ((int)s.length())
#define SIZE(s) ((int)s.size())
int const MAX = 100 + 2;

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	vector<string> data;
	int size = 0;
	for (string s; cin >> s && s != "#"; data.push_back(s))
		size = max(size, SIZE(s));
	bool visited[256] = {false};
	string res = "";
	for (int col = 0; col < size; ++col) {
		for (int row = 0; row < SIZE(data); ++row) {
			if (col < LENGTH(data[row]))
				if (!visited[(int) data[row][col]]) {
					res += data[row][col];
					visited[(int) data[row][col]] = true;
				}
		}
	}
	cout << res << endl;
	return 0;
}
