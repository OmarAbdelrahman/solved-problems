#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct edge {
	int f, t, c;
	edge() { f = t = c = 0; }
	edge(int _f, int _t, int _c)
		: f(_f), t(_t), c(_c) {}
	bool operator < (const edge &e) const {
		if (c != e.c)
			return c < e.c;
		if (f != e.f)
			return f < e.f;
		return t < e.t;
	}
};

struct disjoint_set {
	int *parent;
	int *rank;
	int components;

	disjoint_set(int n) {
		parent = new int[n];
		rank = new int[n];
		components = n;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int find(int s) {
		return parent[s] == s ? s : find(parent[s]);
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
		--components;
	}
};

char to_char(int x) {
	if (x >= 26)
		return (char) (x - 26 + 'a');
	else
		return (char) ('A' + x);
}

bool visited[256][256];
vector<edge> edge_list;

vector<edge> mst(int nodes) {
	disjoint_set s(nodes);
	sort(edge_list.begin(), edge_list.end());
	vector<edge> result;
	for (int i = 0; i < edge_list.size(); i++) {
		if (s.equal(edge_list[i].f, edge_list[i].t))
			continue;
		s.join(edge_list[i].f, edge_list[i].t);
		result.push_back(edge_list[i]);
	}
	return result;
}

int main(int argc, char **argv) {
	int T, n, cost; char ch; scanf("%d", &T);
	for (int turn = 1; T-- != 0; turn++) {
		scanf("%d", &n);
		edge_list.clear();
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == n - 1)
					cin >> cost;
				else
					cin >> cost >> ch;
				if (cost == 0) continue;
				if (!visited[i][j]) {
					edge_list.push_back(edge(i, j, cost));
					visited[i][j] = visited[j][i] = true;
				}
			}
		}
		vector<edge> result = mst(n);
		printf("Case %d:\n", turn);
		for (int i = 0; i < result.size(); i++)
			cout << to_char(result[i].f) << "-" << to_char(result[i].t) << " " << result[i].c << endl;
	}
	return 0;
}

