/*
ID: 1010
PROG: contact
LANG: C++
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;

int a, b, n;
string binary;
map<string, int> freq;

void solve() {
	for (int i = 0; i < binary.size(); ++i)
		for (int size = a; size <= b && size + i <= binary.size(); ++size)
			freq[binary.substr(i, size)]++;
}

bool pred(string s1, string s2) {
	if (s1.size() != s2.size())
		return s1.size() < s2.size();
	return s1 < s2;
}

int main() {
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	scanf("%d%d%d", &a, &b, &n);
	for (string s; cin >> s; binary += s);
	solve();
	map<int, vector<string>, greater<int> > res;
	for (map<string, int>::iterator it = freq.begin(); it != freq.end(); it++)
		res[it->second].push_back(it->first);
	int counter = 0;
	for (map<int, vector<string>, greater<int> >::iterator it = res.begin(); it != res.end() && counter != n; it++, ++counter) {
		printf("%d\n", it->first);
		sort(it->second.begin(), it->second.end(), pred);
		for (int i = 0; i < it->second.size(); ++i) {
			if ((i + 1) % 6 == 0 || i == it->second.size() - 1) 
				cout << it->second[i] << endl;
			else
				cout << it->second[i] << " ";
		}
	}
	return 0;
}