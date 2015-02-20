#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
using namespace std;

#define size(A) ((int)A.size())

int main() {
	string input;
	map<string, string> dictionary;
	string word, meaning;
	while (getline(cin, input)) {
		if (!size(input)) break;
		stringstream ss(input);
		ss >> word >> meaning;
		dictionary[meaning] = word;
	}
	while (cin >> meaning) {
		map<string, string>::iterator it = dictionary.find(meaning);
		(it != dictionary.end()) ? cout << dictionary[meaning] << endl : cout << "eh" << endl;
	}
}