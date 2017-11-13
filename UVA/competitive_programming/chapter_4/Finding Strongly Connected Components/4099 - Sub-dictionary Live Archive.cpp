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
int const MAX = 105;

bool edge[MAX][MAX];

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (string line; getline(cin, line) && line != "0";) {
		int words;
		sscanf(line.c_str(), "%d", &words);
		map<int, string> key;
		map<string, int> val;
		int ID = 0;
		memset(edge, false, sizeof(edge));
		vector<int> outdegree(words, 0);
		for (int i = 0; i < words; i++) {
			string nodes; getline(cin, nodes);
			stringstream sin(nodes);
			string a; sin >> a;
			if (!val.count(a)) {
				val[a] = ID;
				key[ID] = a;
				ID++;
			}
			for (string b; sin >> b;) {
				if (!val.count(b)) {
					val[b] = ID;
					key[ID] = b;
					ID++;
				}
				if (!edge[val[b]][val[a]]) {
					edge[val[b]][val[a]] = true;
					++outdegree[val[b]];
				}
			}
		}
		vector<pair<int, string> > data;
		for (int i = 0; i < words; i++)
			data.push_back(make_pair(outdegree[i], key[i]));
		bool zero;
		do {
			zero = false;
			sort(data.begin(), data.end());
			if (data[0].first == 0) {
				zero = true;
				int a = val[data[0].second];
				for (int i = 1; i < SIZE(data); i++) {
					int b = val[data[i].second];
					if (edge[b][a]) {
						edge[b][a] = false;
						--data[i].first;
					}
				}
				data.erase(data.begin());
			}
		} while (!data.empty() && zero);
		vector<string> res;
		for (int i = 0; i < SIZE(data); i++)
			res.push_back(data[i].second);
		sort(res.begin(), res.end());
		cout << SIZE(res) << endl;
		if (SIZE(res) == 0)
			continue;
		else if (SIZE(res) == 1)
			cout << res[0] << endl;
		else {
			cout << res[0];
			for (int i = 1; i < SIZE(res); i++)
				cout << " " << res[i];
			cout << endl;
		}
	}
	return 0;
}
