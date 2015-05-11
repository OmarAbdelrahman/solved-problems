#include <bits/stdc++.h>
using namespace std;

class InfiniteString {
public:
	string equal(string s, string t) {
		const int ns = s.length();
		const int ts = t.length();

		for (int i = 0; i < ns * ts; ++i) {
			if (s[i % ns] != t[i % ts]) {
				return "Not equal";
			}
		}
		return "Equal";
	}
};

