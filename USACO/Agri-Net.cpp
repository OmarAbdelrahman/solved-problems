/*
TASK: agrinet
LANG: C++
 */

#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

typedef long long i64;
const double eps = 1e-12;
const int oo = 0x3f3f3f3f;
#define all(A) A.begin(), A.end()
typedef vector <vector <int> > AdjacentMatrix;
typedef vector <vector <pair <int, int> > > AdjacentList;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

struct DisjointSet {
	vector <int> parent;
	vector <int> rank;
	int size, componentsNum;
	DisjointSet(int n) {
		componentsNum = size = n;
		parent = vector <int>(n);
		rank = vector <int>(n, 0);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int x) {
		return (parent[x] == x ? x : parent[x] = find(parent[x]));
	}
	void join(int x, int y) {
		int parent1 = find(x);
		int parent2 = find(y);
		if (parent1 == parent2) return;
		if (rank[parent1] == rank[parent2]) rank[parent1]++;
		if (rank[parent1] < rank[parent2]) swap(parent1,parent2);
		parent[parent2] = parent1;
		componentsNum--;
	}
};

struct Edge {
	string id;
	int from, to, cost;
	Edge() {}
	Edge(int f, int t, int c, string i = "") : from(f), to(t), cost(c), id(i) {}
	bool operator < (const Edge& e) const {
		return cost < e.cost;
	}
};

typedef vector <Edge> EdgeList;
pair <int , EdgeList> MST(EdgeList& graph, int nodesNum) {
	sort(graph.begin(), graph.end());
	int edgeNum = graph.size();
	int cost = 0;
	DisjointSet Dsets(nodesNum);
	EdgeList result;
	for (int i = 0; i < edgeNum; i++) {
		if (Dsets.find(graph[i].from) == Dsets.find(graph[i].to)) // in both component
			continue;
		Dsets.join(graph[i].from, graph[i].to);
		cost += graph[i].cost;
		result.push_back(graph[i]);
	}
	return make_pair(cost, result);
}

int main() {
	freopen("agrinet.in", "rt", stdin);
	freopen("agrinet.out", "w", stdout);
	int size;
	scanf("%d", &size);
	EdgeList graph;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			int n; scanf("%d", &n);
			if (i == j) continue;
			graph.push_back(Edge(i, j, n));
		}
	cout << MST(graph, size).first << endl;
	return 0;
}