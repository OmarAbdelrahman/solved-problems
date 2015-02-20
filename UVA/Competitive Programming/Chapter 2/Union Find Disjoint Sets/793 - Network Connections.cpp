#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

struct disjoint_set {
	disjoint_set(int size) {
		parent = new int[size];
		rank = new int[size];
		set_size = new int[size];
		sets_num = size;
		for (int i = 0; i < size; ++i)
			parent[i] = i, rank[i] = 0, set_size[i] = 1;
	}

	int find(int set_num) {
		return parent[set_num] == set_num ? set_num : find(parent[set_num]);
	}

	bool equal(int s1, int s2) {
		return find(s1) == find(s2);
	}

	void join(int s1, int s2) {
		int p1 = find(s1);
		int p2 = find(s2);
		if (p1 == p2) return;
		if (rank[p1] == rank[p2])
			++rank[p1];
		if (rank[p1] < rank[p2])
			swap(p1, p2);
		parent[p2] = p1;
		set_size[p1] += set_size[p2];
		--sets_num;
	}

	~disjoint_set() {
		delete[] parent;
		delete[] rank;
		delete[] set_size;
	}

	int *parent;
	int *rank, *set_size;
	int sets_num;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	int data_set; cin >> data_set;
	for (bool ok = false; data_set--; ok = true) {
		if (ok) cout << endl;
		int computers; cin >> computers;
		cin.ignore();
		disjoint_set network(computers);
		int succ = 0, un_succ = 0;
		for (string s; getline(cin, s) && !s.empty();) {
			stringstream sin(s);
			char ch; sin >> ch;
			int a, b; sin >> a >> b;
			--a, --b;
			if (ch == 'c') {
				network.join(a, b);
			} else {
				if (network.equal(a, b))
					++succ;
				else
					++un_succ;
			}
		}
		printf("%d,%d\n", succ, un_succ);
	}
	return 0;
}