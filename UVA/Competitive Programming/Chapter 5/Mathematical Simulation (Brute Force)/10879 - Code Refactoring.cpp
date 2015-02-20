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

int main()
{
	int T; cin >> T;
	for (int c = 1; T--; ++c)
	{
		int n; cin >> n;
		int r1[2];
		int r2[2];
		int cnt = 0;
		for (int i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				++cnt;
				if (cnt == 1)
				{
					r1[0] = i;
					r1[1] = n / i;
				}
				else if (cnt == 2)
				{
					r2[0] = i;
					r2[1] = n / i;
					break;
				}
			}
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n", c, n, r1[0], r1[1], r2[0], r2[1]);
	}
	return 0;
}