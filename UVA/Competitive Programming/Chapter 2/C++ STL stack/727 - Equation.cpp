#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

typedef long long int64;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())

int compare(char a, char b) {
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return 1;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	return 0;
}

void popUntil(string &res, stack<char> &s) {
	for (; !s.empty(); s.pop()) {
		if (s.top() == '(') {
			s.pop();
			break;
		}
		res += s.top();
	}
}

string solve(string input) {
	string res = "";
	stack<char> parser;
	int n = LENGTH(input);
	for (int i = 0; i < n; ++i) {
		if (input[i] >= '0' && input[i] <= '9') {
			res += input[i];
		} else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*') {
			for (; !parser.empty() && parser.top() != '(' && compare(input[i], parser.top()) <= 0; parser.pop())
				res += parser.top();
			parser.push(input[i]);
		} else if (input[i] == '(') {
			parser.push(input[i]);
		} else if (input[i] == ')') {
			popUntil(res, parser);
		}
	}
	for (; !parser.empty(); parser.pop())
		res += parser.top();
	return res;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int T; cin >> T;
	cin.ignore();
	string t; getline(cin, t);
	for (string input; T-- != 0; input.clear()) {
		for (string ch; getline(cin, ch) && ch != ""; input += ch);
		cout << solve(input) << endl;
		if (T != 0) puts("");
	}
	return 0;
}
