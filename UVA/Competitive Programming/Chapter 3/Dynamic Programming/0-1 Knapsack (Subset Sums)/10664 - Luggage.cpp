#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <numeric>
#include <sstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vint;

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define ALL(a) a.begin(), a.end()
#define REP(i, n) for (int i = 0; i < n; i++)
#define MAX 10000 + 5

vint w;
int meme[205][25], n;

vint parse(string &s) {
	stringstream sin(s);
	vint data;
	for (int t; sin >> t; data.push_back(t));
	return data;
}

int solve(int val, int indx) {
	if (indx >= n)
		return 0;
	int &ret = meme[val][indx];
	if (ret != -1)
		return ret;
	ret = 0;
	if (val >= w[indx])
		ret = max(solve(val - w[indx], indx + 1) + w[indx], solve(val, indx + 1));
	else
		ret = solve(val, indx + 1);
	return ret;
}

int main() {
	int TC; cin >> TC;
	cin.ignore();
	while (TC--) {
		string t; getline(cin, t);
		w = parse(t);
		n = SIZE(w);
		int sum = accumulate(ALL(w), 0);
		memset(meme, -1, sizeof meme);
		if (sum % 2 || solve(sum >> 1, 0) != sum >> 1)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}