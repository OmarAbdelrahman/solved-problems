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

int main(int argc, char **args) {
	string s1, s2;
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		cin >> s1 >> s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		stringstream sin;
		sin << s1 << " " << s2;
		int r1, r2; sin >> r1 >> r2;
		int r = r1 + r2;
		stringstream res;
		res << r;
		string result = res.str();
		reverse(result.begin(), result.end());
		while (result[0] == '0')
			result.erase(result.begin());
		cout << result << endl;
	}
	return 0;
}