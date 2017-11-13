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

vector<string> parse(string str) {
	stringstream sin(str);
	vector<string> res;
	for (string temp; sin >> temp; res.push_back(temp));
	return res;
}

int toInt(string str) {
	stringstream sin(str);
	int n; sin >> n;
	return n;
}

int nextChoos(int x) {
	int c = x & -x, r = x + c;
	return (((r ^ x) >> 2) / c) | r;
}

void print(vector<string> paper, int size) {
	int n = paper.size();
	cout << "Size " << size << endl;
	vector<vector<int> > res;
	for (int mask = (1 << size) - 1; mask < 1 << n; mask = nextChoos(mask)) {
		vector<int> temp;
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
				temp.push_back(i);
		res.push_back(temp);
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i) {
		bool first = true;
		for (int j = 0; j < size; ++j)
			if (first) {
				cout << paper[res[i][j]];
				first = false;
			} else
				cout << ", " << paper[res[i][j]];
		cout << endl;
	}
}

int main() {
	int T; scanf("%d", &T);
	cin.ignore();
	string input; getline(cin, input);
	while (T--) {
		getline(cin, input);
		vector<string> demand = parse(input);
		vector<string> newsPaper;
		for (string str; getline(cin, str) && str != ""; newsPaper.push_back(str));
		if (demand.size() == 1) {
			if (demand[0] == "*") {
				for (int i = 1; i <= newsPaper.size(); ++i) {
					print(newsPaper, i);
					puts("");
				}
			} else {
				int m = toInt(demand[0]);
				print(newsPaper, m);
				puts("");
			}
		} else {
			int s = toInt(demand[0]);
			int e = toInt(demand[1]);
			for (int i = s; i <= e; ++i) {
				print(newsPaper, i);
				puts("");
			}
		}
		if (T) puts("");
	}
	return 0;
}