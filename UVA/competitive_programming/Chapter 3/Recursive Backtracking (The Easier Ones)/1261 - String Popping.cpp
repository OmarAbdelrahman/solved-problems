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

struct io {
	template<class T> inline static T next() {
		T n; std::cin >> n;
		return n;
	}
};

static bool can(string s) {
	if (s.empty()) return true;
	bool ok = false;
	for (int i = 0, j; i < s.size() && !ok; i++) {
		for (j = i; j < s.size() && s[i] == s[j]; j++);
		if (j - i >= 2)
			ok |= can(s.substr(0, i) + s.substr(j));
		i = j - 1;
	}
	return ok;
}

int main(int argc, char **args) {
	for (int T = io::next<int>(); T-- > 0;) {
		printf("%d\n", can(io::next<string>()) ? 1 : 0);
	}
	return 0;
}