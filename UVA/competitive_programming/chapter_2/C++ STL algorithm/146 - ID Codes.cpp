#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

#define LENGTH(a) ((int)a.length())

int main() {
	int cn;
	string word, print;
	while (cin >> word && word != "#") {
		cn = 0;
		print = "";
		do {
			cn++;
			if (cn == 2) {
				print = word;
				break;
			}
		} while (next_permutation(word.begin(), word.end()));
		if (LENGTH(print) == 0)
			puts("No Successor");
		else
			cout << print << endl;
	}
	return 0;
}
