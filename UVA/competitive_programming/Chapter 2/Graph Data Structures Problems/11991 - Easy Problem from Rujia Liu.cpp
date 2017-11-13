#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

#define SIZE(a) ((int)a.size())

int main() {
	for (int n, m; cin >> n >> m;) {
		map<int, vector<int> > adj_list;
		for (int i = 0, num; i < n; ++i) {
			cin >> num;
			adj_list[num].push_back(i + 1);
		}
		for (int i = 0, num, indx; i < m; ++i) {
			cin >> indx >> num;
			if (indx > SIZE(adj_list[num]))
				cout << 0 << endl;
			else
				cout << adj_list[num][indx - 1] << endl;
		}
	}
	return 0;
}
