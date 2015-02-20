//#include <vector>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//struct DisjointSet {
//	DisjointSet(int n) {
//		parent = vector <int>(n);
//		rank = vector <int>(n, 0);
//		componentsNumber = n;
//		for (int i = 0; i < n; ++i)
//			parent[i] = i;
//	}
//	int Find(int n) {
//		return (n == parent[n] ? n : parent[n] = Find(parent[n]));
//	}
//	void Union(int x, int y) {
//		int X = Find(x);
//		int Y = Find(y);
//		if (X == Y) return;
//		if (rank[X] == rank[Y])
//			rank[X]++;
//		if (rank[X] > rank[Y]) {
//			parent[Y] = X;
//		} else {
//			parent[X] = y;
//		}
//		componentsNumber--;
//	}
//	bool Equal(int u, int v) {
//		return Find(u) == Find(v);
//	}
//	vector <int> parent, rank;
//	int componentsNumber;
//};
//
//struct edge_t {
//	edge_t() {}
//	edge_t(int f, int t, int c)
//		: from(f), to(t), cost(c) {}
//	bool operator < (const edge_t& e) const {
//		return cost < e.cost;
//	}
//	int from, to, cost;
//};
//
//typedef vector <edge_t> EdgeList;
//pair <int, EdgeList> Kruskal(EdgeList& graph, int nodesNum, int& number) {
//	DisjointSet set(nodesNum);
//	sort(graph.begin(), graph.end());
//	EdgeList result;
//	int totalCost = 0;
//	for (int i = 0; i < int(graph.size()); ++i) {
//		if (set.Equal(graph[i].from, graph[i].to))
//			continue;
//		totalCost += graph[i].cost;
//		result.push_back(graph[i]);
//		set.Union(graph[i].from, graph[i].to);
//	}
//	return make_pair(totalCost, result);
//}
//
//int main() {
//	return 0;
//}
