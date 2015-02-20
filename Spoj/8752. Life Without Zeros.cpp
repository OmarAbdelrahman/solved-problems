/*
ID: 1010
PROG: game1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;

int get(string s) {
	int n;
	sscanf(s.c_str(), "%d", &n);
	return n;
}

string remove(string s) {
	string ss;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] != '0') ss += s[i];
	return ss;
}

int remove(int n) {
	stringstream sin;
	sin << n;
	int res = 0;
	for (int i = 0; i < sin.str().size(); ++i)
		if (sin.str().at(i) != '0')
			res = (res * 10) + (sin.str()[i] - '0');
	return res;
}

string _main(string s1, string s2) {
	int c1 = get(s1) + get(s2);
	int c2 = remove(c1);
	string ss1 = remove(s1);
	string ss2 = remove(s2);
	if (get(ss1) + get(ss2) == c2)
		return "YES";
	return "NO";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << _main(s1, s2) << endl;
	}
	return 0;
}