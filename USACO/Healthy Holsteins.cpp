/*
ID: 1010
PROG: holstein
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;

#define sz(a) ((int)a.size())
#define get_bit(x, i) ((x >> i) & 1)

int vitamins, feeds;
map<int, set<int> > R;

bool check(vector<int>& v, vector<int>& r) {
	for (int i = 0; i < sz(v); ++i)
		if (v[i] < r[i]) return false;
	return true;
}

int main() {
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	scanf("%d", &vitamins);
	vector<int> requirments(vitamins);
	for (int i = 0; i < vitamins; ++i)
		scanf("%d", &requirments[i]);
	scanf("%d", &feeds);
	vector<vector<int> > feed(feeds);
	for (int i = 0; i < feeds; ++i) {
		feed[i] = vector<int>(requirments);
		for (int j = 0; j < sz(feed[i]); ++j)
			scanf("%d", &feed[i][j]);
	}
	int small = 1000000;
	for (int i = 1; i < 1 << feeds; ++i) {
		vector<int> temp(sz(requirments), 0);
		set<int> ans;
		for (int j = 0; j < feeds; ++j)
			if (get_bit(i, j)) {
				for (int k = 0; k < sz(requirments); ++k)
					temp[k] += feed[j][k];
				ans.insert(j);
			}
		if (check(temp, requirments))
			if (sz(ans) < small) {
				small = sz(ans);
				R[small] = ans;
			}
	}
	printf("%d", R.begin()->first);
	for (set<int>::iterator it = R.begin()->second.begin(); it != R.begin()->second.end(); it++)
		printf(" %d", *it + 1);
	printf("\n");
	return 0;
}
