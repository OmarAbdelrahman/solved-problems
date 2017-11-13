#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int solve(string str) {
	for (int i = 0; i < str.size(); ++i)
		if (!isalpha(str[i])) str[i] = ' ';
	int res = 0;
	stringstream sin(str);
	for (string s; sin >> s; ++res);
	return res;
}

int main() {
	for (string str; getline(cin, str);)
		printf("%d\n", solve(str));
	return 0;
}
