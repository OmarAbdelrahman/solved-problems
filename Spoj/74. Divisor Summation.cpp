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
	int TC, n, i, result; scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%d", &n);
		if (n == 1) {
			puts("0");
			continue;
		}
		result = 0;
		for (i = 1; i * i <= n; ++i) {
			if (n % i == 0) {
				result += i;
				if (n / i < n && n / i != i)
					result += (n / i);
			}
		}
		printf("%d\n", result);
	}
	return 0;
}