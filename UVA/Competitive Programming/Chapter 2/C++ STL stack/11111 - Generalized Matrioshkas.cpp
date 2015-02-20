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

#define SIZE(a) ((int)a.size())

string res[] = { ":-( Try again.", ":-) Matrioshka!" };

vector<int> parse(string s)
{
	vector<int> res;
	stringstream sin(s);
	for (int n; sin >> n; res.push_back(n));
	return res;
}

bool solve(vector<int> doll)
{
	stack<int> parser;
	int n = SIZE(doll);
	if (n % 2 != 0)
		return false;
	for (int i = 0; i < n; i++)
	{
		if (doll[i] < 0)
			parser.push(doll[i]);
		else
		{
			int sum = 0;
			while (!parser.empty())
			{
				if (parser.top() < 0)
				{
					if (parser.top() == -doll[i])
					{
						parser.top() = -parser.top();
						break;
					}
					else
						return false;
				}
				sum += abs(parser.top());
				parser.pop();
			}
			if (sum >= doll[i])
				return false;
		}
	}
	for (; !parser.empty(); parser.pop())
		if (parser.top() < 0)
			return false;
	return true;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (string line; getline(cin, line);)
		if (SIZE(line) > 0)
			cout << res[solve(parse(line))] << endl;
	return 0;
}
