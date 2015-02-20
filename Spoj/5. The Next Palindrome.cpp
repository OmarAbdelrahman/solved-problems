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

char num[1000000 + 1];
char result[1000000 + 1];

int main(int argc, char **args) {
	int TC, size, end, i, all_zero;
	scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%s", num);
		strcpy(result, num);
		size = strlen(num);
		end = size >> 1;
		for (i = 0; i < end; ++i)
			result[size - i - 1] = result[i];
		if (strcmp(result, num) > 0) {
			printf("%s\n", result);
			continue;
		}
		if (size % 2 != 0) {
			if (result[size / 2] != '9') {
				result[size / 2]++;
				printf("%s\n", result);
				continue;
			} else {
				result[size / 2] = '0';
			}
		}
		for (i = end - 1; i >= 0; --i) {
			if (result[i] != '9') {
				result[i] = result[size - i - 1] = (result[i] + 1);
				if (strcmp(result, num) > 0) {
					printf("%s\n", result);
					break;
				}
			} else
				result[i] = result[size - i - 1] = '0';
		}
		all_zero = 1;
		for (i = 0; i < size; ++i)
			if (result[i] != '0') {
				all_zero = 0;
				break;
			}
		if (all_zero) {
			result[0] = '1';
			printf("%s1\n", result);
		}
	}
	return 0;
}