#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstdio>
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

int count;
map<string, int> nameID;

int getID(string name) {
	if (nameID.find(name) == nameID.end())
		nameID[name] = ::count++;
	return nameID[name];
}

int main() {
	int cases; cin >> cases;
	while (cases--) {
		int friendShips;
		cin >> friendShips;
		::count = 0, nameID.clear();
		disjoint_set set(friendShips << 1);
		for (int i = 0; i < friendShips; ++i) {
			string one, two;
			cin >> one >> two;
			int o = getID(one);
			int t = getID(two);
			if (set.equal(o, t)) {
				cout << set.set_size[set.find(o)] << endl;
				continue;
			}
			set.join(o, t);
			cout << set.set_size[set.find(o)] << endl;
		}
	}
	return 0;
}