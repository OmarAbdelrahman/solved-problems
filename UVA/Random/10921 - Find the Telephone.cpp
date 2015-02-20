#include <string>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

void pre_calculation(map<char, int>& value) {
	value['1'] = 1, value['0'] = 0;
	for (char i = 'A'; i <= 'C'; ++i)
		value[i] = 2;
	for (char i = 'D'; i <= 'F'; ++i)
		value[i] = 3;
	for (char i = 'G'; i <= 'I'; ++i)
		value[i] = 4;
	for (char i = 'J'; i <= 'L'; ++i)
		value[i] = 5;
	for (char i = 'M'; i <= 'O'; ++i)
		value[i] = 6;
	for (char i = 'P'; i <= 'S'; ++i)
		value[i] = 7;
	for (char i = 'T'; i <= 'V'; ++i)
		value[i] = 8;
	for (char i = 'W'; i <= 'Z'; ++i)
		value[i] = 9;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	map<char, int> value;
	pre_calculation(value);
	string input;
	while (cin >> input) {
		int n = (int)input.size();
		for (int i = 0; i < n; ++i) if (input[i] != '-') 
			input[i] = value[input[i]] + '0';
		cout << input << endl;
	}
	return 0;
}