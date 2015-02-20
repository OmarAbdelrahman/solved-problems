#include <string>
#include <cstdio>
#include <iostream>

using namespace std;
#define sz(a) (int(a.size()))

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	string s, t;
	while (cin >> s >> t) {
		for (int index = 0; index < sz(t); ++index)
			if (s[0] == t[index]) s.erase(s.begin());
		if (s.empty()) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}