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

int const MAXC = 201;
int const MAXL = 100005;

bool dp[MAXC][MAXL];
int path[MAXC][MAXL];
int sum[MAXC], length;
int car[MAXC], ncar;

void get_path(int index, int left) {
	if (index == 0 || left < 0)
		return;
	if (path[index][left] > -1) {
		if (path[index][left] == 0)
			get_path(index - 1, left - car[index]);
		else
			get_path(index - 1, left);
		printf(path[index][left] == 0 ? "port\n" : "starboard\n");
	}
}

int main(int argc, char **args) {
	int TC; scanf("%d", &TC);
	while (TC-- > 0) {
		scanf("%d", &length);
		length *= 100;
		int value;
		sum[0] = 0, ncar = 1;
		while (scanf("%d", &value) && value != 0) {
			if (ncar < MAXC) {
				sum[ncar] = sum[ncar - 1] + value;
				car[ncar] = value;
				ncar++;
			}
		}
		memset(dp, false, sizeof(dp));
		memset(path, -1, sizeof(path));
		pair<int, int> result(0, 0);
		dp[0][0] = true;
		for (int i = 0; i + 1 < ncar; ++i)
			for (int left = 0; left <= length; ++left)
				if (dp[i][left]) {
					int right = sum[i] - left;
					if (left + car[i + 1] <= length) {
						dp[i + 1][left + car[i + 1]] = true;
						path[i + 1][left + car[i + 1]] = 0;
						result = make_pair(i + 1, left + car[i + 1]);
					}
					if (right + car[i + 1] <= length) {
						dp[i + 1][left] = true;
						path[i + 1][left] = 1;
						result = make_pair(i + 1, left);
					}
				}
		printf("%d\n", result.first);
		get_path(result.first, result.second);
		if (TC > 0) puts("");
	}
	return 0;
}