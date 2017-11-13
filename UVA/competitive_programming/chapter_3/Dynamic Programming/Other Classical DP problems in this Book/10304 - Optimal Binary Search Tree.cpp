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

int const MAX = 251;
int sum[MAX];
int memo[MAX][MAX];
int A[MAX], n;

int solve(int left, int right)
{
	if (right <= left)
		return 0;
	int &res = memo[left][right];
	if (res != -1) return res;
	res = INT_MAX;
	for (int index = left; index <= right; ++index)
		res = min(res, solve(left, index - 1) + solve(index + 1, right) + (sum[right] - sum[left - 1]) - A[index]);
	return res;
}

int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		sum[0] = A[0];
		for (int i = 1; i < n; ++i)
			sum[i] = sum[i - 1] + A[i];
		memset(memo, -1, sizeof(memo));
		cout << solve(0, n - 1) << endl;
	}
	return 0;
}