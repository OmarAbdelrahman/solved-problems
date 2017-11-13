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

bool conn[50][50];
bool vis[50];

vector<string> split(string s)
{
	stringstream sin(s);
	vector<string> parts;
	for (string t; sin >> t; parts.push_back(t));
	return parts;
}

int main()
{
	for (string s; cin >> s && s != "#";)
	{
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == ';')
				s[i] = ' ';
		vector<string> parts = split(s);
		fill(vis, vis + 50, false);
		for (int i = 0; i < 50; ++i)
			fill(conn[i], conn[i] + 50, false);
		string perm = "";
		for (int i = 0; i < parts.size(); ++i)
		{
			char src = parts[i][0];
			if (!vis[src - 'A'])
				perm += src;
			vis[src - 'A'] = true;
			for (int j = 2; j < parts[i].length(); ++j)
			{
				if (!vis[parts[i][j] - 'A'])
					perm += parts[i][j];
				vis[parts[i][j] - 'A'] = true;
				conn[src - 'A'][parts[i][j] - 'A'] = true;
				conn[parts[i][j] - 'A'][src - 'A'] = true;
			}
		}
		sort(perm.begin(), perm.end());
		pair<string, int> res = make_pair("", INT_MAX);
		do
		{
			int maxBand = -1;
			for (int i = 0; i < perm.length(); ++i)
				for (int j = i + 1; j < perm.length(); ++j)
					if (conn[perm[i] - 'A'][perm[j] - 'A'])
						maxBand = max(maxBand, j - i);
			if (maxBand < res.second)
			{
				res.second = maxBand;
				res.first = perm;
			}
		}
		while (next_permutation(perm.begin(), perm.end()));
		for (int i = 0; i < res.first.length(); ++i)
			cout << res.first[i] << " ";
		cout << "-> " << res.second << endl;
	}
	return 0;
}