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
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())

bool conn[27][27];
bool notUsed[27];
char final[27];
int to[27];

void get(int depth, int size) {
	if (depth == size) {
		cout << final << endl;
	} else for (int i = 0; i < 26; ++i) {
		if (notUsed[i] && !to[i]) {
			notUsed[i] = false;
			for (int j = 0; j < 26; ++j)
				if (conn[i][j] && notUsed[j])
					--to[j];
			final[depth] = i + 'a';
			get(depth + 1, size);
			notUsed[i] = true;
			for (int j = 0; j < 26; ++j)
				if (conn[i][j] && notUsed[j])
					++to[j];
		}
	}
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	bool f = true;
	for (string n; getline(cin, n); f = false) {
		if (!f) puts("");
		memset(to, 0, sizeof(to));
		memset(notUsed, false, sizeof(notUsed));
		memset(conn, false, sizeof(conn));
		int nodes = 0;
		for (int i = 0; i < LENGTH(n); ++i)
			if (n[i] >= 'a' && n[i] <= 'z' && !notUsed[n[i] - 'a']) {
				notUsed[n[i] - 'a'] = true;
				++nodes;
			}
		final[nodes] = '\0';
		string constraints; getline(cin, constraints);
		stringstream sin(constraints);
		for (char a, b; sin >> a >> b; conn[a - 'a'][b - 'a'] = true, ++to[b - 'a']);
		get(0, nodes);
	}
	return 0;
}
