#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	for (int n; cin >> n && n;) {
		cin.ignore();
		vector<string> data(n);
		vector<int> X(n);
		int small = 1 << 30;
		for (int i = 0; i < n; ++i) {
			getline(cin, data[i]);
			int space = count(data[i].begin(), data[i].end(), ' ');
			if (space < small) small = space;
			X[i] = count(data[i].begin(), data[i].end(), 'X');
		}
		int res = 0;
		for (int i = 0; i < n; ++i)
			res += 25 - (X[i] + small);
		cout << res << endl;
	}
	return 0;
}
