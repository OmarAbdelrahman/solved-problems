#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	map<string, set<string> > answer;
	while (n--) {
		string country, name;
		cin >> country;
		cin.ignore();
		getline(cin, name);
		answer[country].insert(name);
	}
	for (map<string, set<string> >::iterator it = answer.begin(); it != answer.end(); it++)
		cout << it->first << " " << (int)it->second.size() << endl;
	return 0;
}