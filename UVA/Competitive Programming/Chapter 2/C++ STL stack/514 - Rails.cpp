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

typedef long long lli;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
int const MAX = 100;
int const INF = 1000000;

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int n; cin >> n && n;)
	{
		for (int val; cin >> val && val;)
		{
			stack<int> A;
			stack<int> station;
			A.push(val);
			for (int i = 1; i < n; i++)
			{
				cin >> val;
				A.push(val);
			}
			for (int i = n; i >= 1;)
			{
				if (!station.empty() && station.top() == i)
				{
					station.pop();
					i--;
					continue;
				}
				if (A.empty())
					break;
				if (A.top() != i)
					station.push(A.top());
				else
					i--;
				A.pop();
			}
			if (A.empty() && station.empty())
				puts("Yes");
			else
				puts("No");
		}
		cout << endl;
	}
	return 0;
}
