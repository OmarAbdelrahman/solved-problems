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

string P, T;
int n, m;
vector<int> b;

void failure_function() {
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j])
			j = b[j];
		i++; j++;
		b[i] = j;
	}
}

void kmp_search(bool& ok) {
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j])
			j = b[j];
		i++; j++;
		if (j == m) {
			ok = true;
			printf("%d\n", i - j);
			j = b[j];
		}
	}
}

int main(int argc, char **args) {
	while (scanf("%d", &m) != EOF) {
		cin >> P;
		cin >> T;
		n = T.length();
		b = vector<int>(m + 1);
		failure_function();
		bool ok = false;
		kmp_search(ok);
		if (!ok)
			puts("");
	}
	return 0;
}