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

bool prime[100000 + 5];

int main(int argc, char **args) {
	int TC, a, b, size; scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%d%d", &a, &b);
		size = b - a + 1;
		for (int i = 0; i < size; ++i)
			prime[i] = true;
		for (int i = 2; i * i <= b; ++i) {
			int start = a / i;
			start *= i;
			for (int j = start; j <= b; j += i)
				if (i != j && j >= a)
					prime[j - a] = false;
		}
		for (int i = 0; i < size; ++i)
			if (prime[i] && i + a != 1)
				printf("%d\n", i + a);
		if (TC > 0)
			puts("");
	}
	return 0;
}