#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

#define FOREACH(i, c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

struct Node {
	Node() {}
	Node(string _s, int _n):
		s(_s), n(_n) {}
	bool operator < (const Node& node) const {
		return this->n < node.n;
	}
	string s;
	int n;
};

int main() {
	int sets; cin >> sets;
	for (bool first = true; sets--; first = false) {
		if (!first) cout << endl;
		int n, m; cin >> n >> m;
		vector<Node> output;
		for (int i = 0; i < m; ++i) {
			string str; cin >> str;
			int val = 0;
			for (int j = 0; j < n; ++j)
				for (int k = j + 1; k < n; ++k)
					val += str[j] > str[k];
			output.push_back(Node(str, val));
		}
		stable_sort(output.begin(), output.end());
		FOREACH(word, output) cout << word->s << endl;
	}
	return 0;
}
