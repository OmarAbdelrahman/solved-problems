#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
using namespace std;

#define size(A) ((int)A.size())
#define All(A) A.begin(), A.end()
#define	For(i, v, Limit) for (int i = v; i < Limit; i++)
#define DFor(i, Limit, v) for (int i = Limit; i >= v; i--)

int main() {
	int g;
	string s, t;
	vector<string> v;
	while (cin >> g && g != 0) {
		cin >> s;
		for (int i = 0, c = 0; i < size(s); i++, c++) {
			t += s[i];
			if (c == size(s) / g - 1) {
				v.push_back(t);
				c = -1, t = "";
			}
		}
		for (int i = 0; i < size(v); ++i) {
			reverse(v[i].begin(), v[i].end());
			cout << v[i];
		}
		cout << endl;
		v.clear();
	}
	return 0;
}