#include <iostream>
#include <string>
#include <cstdio>
#include <string.h>
using namespace std;

#define MAX 256

pair<string, int> solve(string str) {
	int value[MAX];
	memset(value, 0, sizeof(value));
	for (int i = 0; i < str.size(); ++i)
		if (isalpha(str[i])) ++value[str[i]];
	int big = -1;
	for (int i = 0; i < MAX; ++i)
		big = max(big, value[i]);
	string res;
	for (int i = 'A'; i <= 'Z'; ++i)
		if (value[i] == big) res += char(i);
	for (int i = 'a'; i <= 'z'; ++i)
		if (value[i] == big) res += char(i);
	return make_pair(res, big);
}

int main() {
	for (string str; getline(cin, str);) {
		pair<string, int> res = solve(str);
		printf("%s %d\n", res.first.c_str(), res.second);
	}
	return 0;
}