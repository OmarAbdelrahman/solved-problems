/*
ID: 1010
PROG: heritage
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string preOrder;

string f(string in) {
	if (in.size() == 0) return "";
	char root = preOrder[0];
	preOrder.erase(preOrder.begin());
	if (in.size() == 1) return in;
	int pos = in.find(root);
	string leftTree = in.substr(0, pos);
	string rightTree = in.substr(pos + 1);
	string shemal = f(leftTree);
	string yemen = f(rightTree);
	return shemal + yemen + root;
}

int main() {
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);
	string inOrder;
	cin >> inOrder;
	cin >> preOrder;
	cout << f(inOrder) << endl;
	return 0;
}
