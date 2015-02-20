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

map<pair<int, string>, int> rep;
char str[34];

int main(int argc, char **args) {
	int TC, n, i, ID; scanf("%d", &TC);
	while (TC-- > 0) {
		rep.clear();
		scanf("%d", &n);
		cin.ignore();
		for (i = 0; i < n; ++i) {
			gets(str);
			rep[make_pair((str[0] - '0') * 10 + (str[1] - '0'), str)]++;
		}
		for (map<pair<int, string>, int>::iterator it = rep.begin(); it != rep.end(); it++) {
			printf("%s%d\n", it->first.second.c_str(), it->second);
		}
		if (TC > 0) puts("");
	}
	return 0;
}