#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define SIZE(a) ((int)a.size())

template<class T> void parse(string str, vector<T>& v) {
	stringstream sin(str);
	for (T n; sin >> n; v.push_back(n));
}

int main() {
	int cases; cin >> cases;
	cin.ignore();
	for (bool first = true; cases--; first = false) {
		if (!first) cout << endl;
		string line; getline(cin, line); 
		getline(cin, line);
		vector<int> index;
		parse(line, index);
		getline(cin, line);
		vector<string> data;
		parse(line, data);
		int size = SIZE(index);
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				if (i == index[j] - 1) {
					cout << data[j] << endl;
					break;
				}
	}
	return 0;
}