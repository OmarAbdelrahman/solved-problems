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

int solve(int r, int n)
{
	if (n * 26 + n < r)
		return -1;
	int roads = r - n;
	if (roads <= 0)
		return 0;
	if (roads < n)
		return 1;
	if (roads % n == 0)
		return roads / n;
	return roads / n + 1;
}

int main()
{
	int R, N;
	for (int c = 1; scanf("%d%d", &R, &N); ++c)
	{
		if (R == 0 && N == 0)
			break;
		printf("Case %d: ", c);
		int res = solve(R, N);
		if (res == -1)
			printf("impossible\n");
		else
			printf("%d\n", res);
	}
	return 0;
}