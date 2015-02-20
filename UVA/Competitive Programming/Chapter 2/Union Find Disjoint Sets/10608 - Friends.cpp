#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

#define all(A) A.begin(), A.end()

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
	int test; scanf("%d", &test);
	while (test--) {
		int nodes, edges;
		scanf("%d%d", &nodes, &edges);
		disjoint_set set(nodes + 10);
		for (int i = 0; i < edges; i++) {
			int a, b; scanf("%d%d", &a, &b);
			set.join(a - 1, b - 1);
		}
		vector<int> setNumbers(nodes + 10, 0);
		for (size_t i = 0; i < nodes; i++)
			setNumbers[set.find(i)]++;
		printf("%d\n", *max_element(all(setNumbers)));
	}
	return 0;
}