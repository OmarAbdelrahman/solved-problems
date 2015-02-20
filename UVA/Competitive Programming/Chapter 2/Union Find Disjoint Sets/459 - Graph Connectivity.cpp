#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct disjoint_set {
	disjoint_set(int size) {
		parent = new int[size];
		rank = new int[size];
		set_size = new int[size];
		num_sets = size;
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
		--num_sets;
	}

	~disjoint_set() {
		delete[] parent;
		delete[] rank;
		delete[] set_size;
	}

	int *parent;
	int *rank, *set_size;
	int num_sets;
};

int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		char character, i;
		cin >> character;
		cin.ignore();
		map<char, int> value;
		for (i = 'A'; i <= character; ++i)
			value[i] = (int)(i - 'A');
		string connection;
		disjoint_set set(value[character] + 1);
		while (getline(cin, connection) && !connection.empty())
			set.join(value[connection[0]], value[connection[1]]);
		printf("%d\n", set.num_sets);
		if (cases) cout << endl;
	}
	return 0;
}