/*
ID: 1010
PROG: zerosum
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<sstream>
using namespace std;

#define sz(a) ((int)a.size())

int size;
string ops = "+- ";
string combs;
set<string> A;

void solve(int L = 0) {
	if (L == sz(combs)) {
		string answer = "1", temp = "1";
		for (int i = 0; i < sz(combs); ++i) {
			if (combs[i] != ' ')
				temp += combs[i];
			answer += combs[i];
			answer += (i + 2) + '0';
			temp += (i + 2) + '0';
		}
		int sum = 0;
		while (temp[0] >= '1' && temp[0] <= '9')
			sum = (sum * 10) + (temp[0] - '0'), temp.erase(temp.begin());
		istringstream sin(temp);
		char sign;
		int number;
		while (sin >> sign >> number)
			sum += sign == '+' ? number : -number;
		if (!sum) A.insert(answer);
	} else for (int i = 0; i < 3; ++i) {
		combs[L] = ops[i];
		solve(L + 1);
	}
}

int main() {
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	scanf("%d", &size);
	combs.resize(size - 1);
	solve();
	for (set<string>::iterator it = A.begin(); it != A.end(); it++)
		cout << *it << endl;
	return 0;
}