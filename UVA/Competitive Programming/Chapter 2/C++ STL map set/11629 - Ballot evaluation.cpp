#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define FOREACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

template<class T> void parse(string s, vector<T>& v) {
	stringstream sin(s);
	for (string ss; sin >> ss; v.push_back(ss));
}

double to_double(string s) {
	stringstream sin(s);
	double n; sin >> n;
	return n;
}

int main() {
	for (int parties, guesses; cin >> parties >> guesses;) {
		map<string, int> vote;
		for (int i = 0; i < parties; ++i) {
			string key;
			double value;
			cin >> key >> value;
			vote[key] = value * 10;
		}
		cin.ignore();
		for (int i = 0; i < guesses; ++i) {
			string s; getline(cin, s);
			for (int j = 0; j < LENGTH(s); ++j)
				if (s[j] == '+') s[j] = ' ';
			vector<string> data;
			parse(s, data);
			int sum = 0;
			int guessed_number = to_double(data[SIZE(data) - 1]) * 10;
			for (int j = 0; j < SIZE(data) - 2; ++j)
				sum += vote[data[j]];
			printf("Guess #%d ", i + 1);
			string operation = data[SIZE(data) - 2];
			if (operation == "<") {
				if (sum < guessed_number)
					printf("was correct.\n");
				else
					printf("was incorrect.\n");
			} else if (operation == ">") {
				if (sum > guessed_number)
					printf("was correct.\n");
				else
					printf("was incorrect.\n");
			} else if (operation == ">=") {
				if (sum >= guessed_number)
					printf("was correct.\n");
				else
					printf("was incorrect.\n");
			} else if (operation == "<=") {
				if (sum <= guessed_number)
					printf("was correct.\n");
				else
					printf("was incorrect.\n");
			} else if (operation == "=") {
				if (sum == guessed_number)
					printf("was correct.\n");
				else
					printf("was incorrect.\n");
			}
		}
	}
	return 0;
}