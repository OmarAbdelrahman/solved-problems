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

typedef long long i64;

i64 trailing_zeros_in_factorial(int n) {
	i64 result = 0;
	while (n > 0) {
		result += (n / 5);
		n /= 5;
	}
	return result;
}

int main(int argc, char **args) {
	int TC, n; scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%d", &n);
		printf("%ld\n", trailing_zeros_in_factorial(n));
	}
	return 0;
}