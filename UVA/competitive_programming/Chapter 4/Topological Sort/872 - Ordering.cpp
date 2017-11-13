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

typedef unsigned long long int64;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())

bool conn[27][27];
bool notUsed[27];
char final[27];
int to[27];
int res;

void get(int depth, int size) {
	if (depth == size) {
		cout << final[0];
		for (int i = 1; i < size; ++i)
			cout << " " << final[i];
		cout << endl;
		++::res;
	} else for (int i = 0; i < 26; ++i) {
		if (notUsed[i] && !to[i]) {
			notUsed[i] = false;
			for (int j = 0; j < 26; ++j)
				if (conn[i][j] && notUsed[j])
					--to[j];
			final[depth] = i + 'A';
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
	int T; cin >> T;
	cin.ignore();
	string temp; getline(cin, temp);
	while (T-- != 0) {
		memset(to, 0, sizeof(to));
		memset(notUsed, false, sizeof(notUsed));
		memset(conn, false, sizeof(conn));
		string n; getline(cin, n);
		int nodes = 0;
		for (int i = 0; i < LENGTH(n); ++i)
			if (n[i] >= 'A' && n[i] <= 'Z' && !notUsed[n[i] - 'A']) {
				notUsed[n[i] - 'A'] = true;
				++nodes;
			}
		final[nodes] = '\0';
		for (string constraints; getline(cin, constraints) && constraints != "";) {
			stringstream sin(constraints);
			for (string constraint; sin >> constraint;) {
				conn[constraint[0] - 'A'][constraint[2] - 'A'] = true;
				++to[constraint[2] - 'A'];
			}
		}
		::res = 0;
		get(0, nodes);
		if (res == 0) puts("NO");
		if (T) puts("");
	}
	return 0;
}
