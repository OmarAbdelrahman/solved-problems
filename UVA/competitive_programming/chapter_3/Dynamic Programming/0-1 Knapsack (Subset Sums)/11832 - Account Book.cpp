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

typedef long long int64;

int const MAXN = 41;
int const MAXSUM = 2 * MAXN * 1000 + 2;
int const OFFSET = (MAXN - 1) * 1000;

int transactions;
int T[MAXN];
int neg[MAXN][MAXSUM];
int pos[MAXN][MAXSUM];
bool ab[MAXN];
bool be[MAXN];

int solve(int index, int curSum, int cashFlow)
{
	if (index == transactions)
		return curSum == cashFlow;
	int &negative = neg[index][curSum + OFFSET];
	int &positive = pos[index][curSum + OFFSET];
	if (negative != -1 && positive != -1)
		return positive || negative;
	positive = negative = 0;
	if (curSum + T[index] < MAXSUM)
		positive |= solve(index + 1, curSum + T[index], cashFlow);
	if (curSum - T[index] + OFFSET < MAXSUM)
		negative |= solve(index + 1, curSum - T[index], cashFlow);
	if (negative)
		be[index] = true;
	if (positive)
		ab[index] = true;
	return negative || positive;
}

int main()
{
	for (int cashFlow; cin >> transactions >> cashFlow;)
	{
		if (transactions == 0 && cashFlow == 0)
			break;
		for (int i = 0; i < transactions; ++i)
			cin >> T[i];
		fill(ab, ab + MAXN, false);
		fill(be, be + MAXN, false);
		for (int i = 0; i < MAXN; ++i)
		{
			fill(neg[i], neg[i] + MAXSUM, -1);
			fill(pos[i], pos[i] + MAXSUM, -1);
		}
		if (!solve(0, 0, cashFlow))
			puts("*");
		else
		{
			for (int i = 0; i < transactions; ++i)
				if (ab[i] && be[i]) printf("?"); else if (ab[i]) printf("+"); else if (be[i]) printf("-");
			puts("");
		}
	}
	return 0;
}