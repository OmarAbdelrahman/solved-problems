#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vint;

#define REP(i, n) for (i = 0; i < n; i++)
#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define ALL(a) a.begin(), a.end()

int to_int(string &s) {
	int n; sscanf(s.c_str(), "%d", &n);
	return n;
}

vint lis(vint data) {
	int i, LIS = 1;
	vint::iterator it;
	vint pos(SIZE(data)), res;
	res.push_back(data[0]);
	for (i = 1; i < SIZE(data); i++) {
		it = lower_bound(res.begin(), res.end(), data[i]);
		pos[i] = (int)(it - res.begin());
		if (it == res.end())
			res.push_back(data[i]);
		else
			*it = data[i];
	}
	LIS = SIZE(res) - 1;
	for (i = SIZE(data) - 1; i >= 0; --i)
		if (pos[i] == LIS)
			res[LIS--] = data[i];
	return res;
}

int main() {
	int TC; scanf("%d", &TC);
	cin.ignore();
	string tt; getline(cin, tt);
	for (int i; TC--;) {
		vint data;
		for (string t; getline(cin, t) && t != ""; data.push_back(to_int(t)));
		vint res = lis(data);
		printf("Max hits: %d\n", SIZE(res));
		REP(i, SIZE(res)) printf("%d\n", res[i]);
		if (TC) puts("");
	}
	return 0;
}