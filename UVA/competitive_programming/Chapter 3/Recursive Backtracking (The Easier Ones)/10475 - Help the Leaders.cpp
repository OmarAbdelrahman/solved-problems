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

class StringComparator {
public:
	bool operator () (const string &s1, const string &s2) const {
		if (s1.length() != s2.length())
			return s1.length() > s2.length();
		return s1 < s2;
	}
};

class VectorComparator {
public:
	bool operator () (const vector<string> &v1, const vector<string> &v2) const {
		for (int i = 0; i < v1.size(); ++i)
			if (v1[i] != v2[i]) {
				if (v1[i].length() != v2[i].length())
					return v1[i].length() > v2[i].length();
				return v1[i] < v2[i];
			}
		return v1 == v2;
	}
};

int nextChoose(int x) {
	int c = x & -x, r = x + c;
	return (((r ^ x) >> 2) / c) | r;
}

string toUpper(string s) {
	for (int i = 0; i < s.length(); ++i)
		if (isalpha(s[i]))
			s[i] = toupper(s[i]);
	return s;
}

int main() {
	int T; scanf("%d", &T);
	for (int set = 1; T--; ++set) {
		int topics;
		int prohibeted, n;
		scanf("%d%d%d", &topics, &prohibeted, &n);
		cin.ignore();
		vector<string> topic(topics);
		map<string, int> value;
		for (int i = 0; i < topics; ++i) {
			cin >> topic[i];
			topic[i] = toUpper(topic[i]);
			value[topic[i]] = i;
		}
		vector<int> cant(topics, 0);
		for (int i = 0; i < prohibeted; ++i) {
			string s1, s2; cin >> s1 >> s2;
			int v1 = value[toUpper(s1)];
			int v2 = value[toUpper(s2)];
			cant[v1] |= (1 << v2);
			cant[v2] |= (1 << v1);
		}
		vector<vector<string> > res;
		for (int mask = (1 << n) - 1; mask < 1 << topics; mask = nextChoose(mask)) {
			vector<string> speech;
			bool ok = true;
			for (int i = 0; i < topics; ++i) {
				if (mask & (1 << i)) {
					if (mask & cant[value[topic[i]]]) {
						ok = false;
						break;
					}
					speech.push_back(topic[i]);
				}
			}
			if (ok) {
				sort(speech.begin(), speech.end(), StringComparator());
				res.push_back(speech);
			}
		}
		sort(res.begin(), res.end(), VectorComparator());
		printf("Set %d:\n", set);
		for (int i = 0; i < res.size(); ++i) {
			cout << res[i][0];
			for (int j = 1; j < res[i].size(); ++j)
				cout << " " << res[i][j];
			cout << endl;
		}
		puts("");
	}
	return 0;
}