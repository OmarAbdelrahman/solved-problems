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

stack<int> last;
int solution[55];
int pegs[55];

bool is_perfect(const int& x) {
	int y = (int) sqrt(x * 1.0);
	return y * y == x;
}

int main(int argc, char **args) {
	int ball = 1;
	int size = 0;
	while (true) {
		bool ok = false;
		for (int i = 0; i < size; ++i)
			if (is_perfect(ball + pegs[i])) {
				pegs[i] = ball;
				last.push(ball++);
				ok = true;
				break;
			}

		if (!ok) {
			pegs[size] = ball;
			solution[size++] = last.empty() ? 1 : last.top();
			last.push(ball++);
			if (size > 50) break;
		}
	}

	int T, count; cin >> T;
	for (cin >> count; T-- > 0; cin >> count) {
		cout << solution[count] << endl;
	}
	return 0;
}