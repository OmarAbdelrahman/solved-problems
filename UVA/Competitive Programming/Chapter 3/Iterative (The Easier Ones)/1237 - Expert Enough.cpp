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

int const MAXN = 10000 + 5;

struct car {
	string name;
	int low, high;
	car() {}
	car(string n, int l, int h)
		: name(n), low(l), high(h) {}
};

car database[MAXN];

int main(int argc, char **args) {
	string result;
	int TC, D, query, count, value; scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%d", &D);
		for (int i = 0; i < D; ++i)
			cin >> database[i].name >> database[i].low >> database[i].high;
		scanf("%d", &query);
		while (query-- > 0) {
			count = 0;
			result = "";
			scanf("%d", &value);
			for (int i = 0; i < D; ++i) {
				if (value >= database[i].low && value <= database[i].high) {
					result = database[i].name;
					count++;
				}
			}
			if (count != 1) puts("UNDETERMINED"); else cout << result << endl;
		}
		if (TC != 0) puts("");
	}
	return 0;
}