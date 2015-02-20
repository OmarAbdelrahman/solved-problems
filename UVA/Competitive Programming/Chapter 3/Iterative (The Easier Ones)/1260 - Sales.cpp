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
	int TC; cin >> TC;
	while (TC-- > 0) {
		int n; cin >> n;
		vector<int> data(n);
		for (int i = 0; i < n; ++i)
			cin >> data[i];
		int result = 0;
		for (int i = 1; i < n; ++i) {
			int count = 0;
			for (int j = i - 1; j >= 0; --j)
				count += data[j] <= data[i];
			result += count;
		}
		cout << result << endl;
	}
	return 0;
}