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

int const MAX = 10000 + 5;
int const INF = 1 << 30;

int A[MAX];
int res[MAX];
bool L[MAX];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	while (T-- != 0)
	{
		int n; cin >> n;
		int travelTime; cin >> travelTime;
		int cars; cin >> cars;
		int rindx = 0;
		int lindx = 0;
		fill(A, A + MAX, INF);
		for (int i = 0; i < cars; i++)
		{
			cin >> A[i];
			string direction; cin >> direction;
			L[i] = direction[0] == 'l';
		}
		for (; lindx < cars && !L[lindx]; lindx++);
		for (; rindx < cars && L[rindx]; rindx++);
		int time = 0;
		while (lindx < cars || rindx < cars)
		{
			time = max(time, min(A[lindx], A[rindx]));
			for (int i = 0; i < n && A[lindx] <= time; i++)
			{
				res[lindx] = time + travelTime;
				for (++lindx; lindx < cars && !L[lindx]; lindx++);
			}
			time += travelTime;
			time = max(time, min(A[lindx], A[rindx]));
			for (int i = 0; i < n && A[rindx] <= time; i++)
			{
				res[rindx] = time + travelTime;
				for (++rindx; rindx < cars && L[rindx]; rindx++);
			}
			time += travelTime;
		}
		for (int i = 0; i < cars; i++)
			cout << res[i] << endl;
		if (T != 0) cout << endl;
	}
	return 0;
}
