#include <vector>
#include <queue>
using namespace std;

typedef long long Int;
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

struct edge_t {
	edge_t() { }
	edge_t(int n, Int c)
		: node(n), cost(c) {}
	int node;
	Int cost;
};

class compare_t {
public:
	bool operator () (const edge_t& e1, const edge_t& e2) {
		return e1.cost > e2.cost;
	}
};

typedef vector <vector <edge_t> > AdjacentList;
Int Prim(AdjacentList& graph, int N) {
	vector<bool> visited(2000, false);
	priority_queue<edge_t, vector<edge_t>, compare_t> fringe;
	Int totalCost = 0;
	fringe.push(edge_t(0, 0));
	while (!fringe.empty()) {
		edge_t edge = fringe.top();
		fringe.pop();
		if (visited[edge.node]) continue;
		totalCost += edge.cost;
		visited[edge.node] = true;
		foreach (vertex, graph[edge.node]) {
			if (!visited[vertex->node])
				fringe.push(edge_t(vertex->node, vertex->cost));
		}
	}
	return totalCost;
}

int main() {
	return 0;
}
