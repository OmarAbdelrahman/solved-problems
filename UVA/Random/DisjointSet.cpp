//#include <vector>
//#include <algorithm>
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
