#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <sstream>
using namespace std;

struct disjoint_set {
	disjoint_set(int n) {
		parent = vector<int>(n);
		rank = vector<int>(n, 0);
		components_number = n;
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int find(int n) {
		return n == parent[n] ? n : parent[n] = find(parent[n]);
	}
	void join(int x, int y) {
		int X = find(x);
		int Y = find(y);
		if (X == Y) return;
		if (rank[X] == rank[Y])
			rank[X]++;
		if (rank[X] > rank[Y]) {
			parent[Y] = X;
		} else {
			parent[X] = y;
		}
		components_number--;
	}
	bool equal(int u, int v) {
		return find(u) == find(v);
	}
	vector<int> parent, rank;
	int components_number;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cases;
	cin >> cases;
	cin.ignore();
	while (cases--) {
		int edges;
		cin >> edges;
		cin.ignore();
		string statement;
		disjoint_set set(edges + 1);
		int answer[2] = {0, 0};
		while (getline(cin, statement) && !statement.empty()) {
			istringstream sin(statement);
			int one, two; char ch;
			sin >> ch >> one >> two;
			if (ch == 'c')
				set.join(one, two);
			if (ch == 'q')
				answer[set.equal(one, two)]++;
		}
		cout << answer[1] << "," << answer[0] << endl;
		if (cases) cout << endl;
	}
	return 0;
}