/*
TASK: ditch
LANG: C++
 */

#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
#include <bitset>
#include <complex>
#include <cassert>
#include <numeric>

using namespace std;

#define eps                           (1e-12)
#define oo                            (int)1e9
#define sz(A)                         ((int)A.size())
#define All(A)                        A.begin(), A.end()
#define init(A, B)                    memset(A, B, sizeof(A))
#define F(i, v, Limit)                for (int i = v; i < Limit; i++)
#define DF(i, Limit, v)               for (int i = Limit; i >= v; i--)
#define foreach(i, c)                 for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
template <class _Ty> inline           _Ty square(_Ty n) {return n*n;}
template <class _Ty> inline           _Ty cube(_Ty n) {return square(n)*n;}

int n, e, t, m, a, b, c;
vector < vector <int> > adj_m;

int main() {
	freopen("in.in", "rt", stdin);
	while (scanf("%d", &n) != EOF) {
		scanf("%d%d%d", &e, &t, &m);
		adj_m = vector < vector <int> >(n, vector <int>(n, oo));
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			adj_m[a-1][b-1] = c;
		}
		for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
			adj_m[i][j] = min(adj_m[i][j], adj_m[i][k] + adj_m[k][j]);
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (adj_m[i][e-1] <= t) ++cnt;
		printf("%d\n", cnt+1);
	}
	return 0;
}






//=======================================================================================================

/*
TASK: ditch
LANG: C++
 */

#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
#include <bitset>
#include <complex>
#include <cassert>
#include <numeric>

using namespace std;

#define eps                           (1e-12)
#define oo                            (int)1e9
#define sz(A)                         ((int)A.size())
#define All(A)                        A.begin(), A.end()
#define init(A, B)                    memset(A, B, sizeof(A))
#define F(i, v, Limit)                for (int i = v; i < Limit; i++)
#define DF(i, Limit, v)               for (int i = Limit; i >= v; i--)
#define foreach(i, c)                 for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
template <class _Ty> inline           _Ty square(_Ty n) {return n*n;}
template <class _Ty> inline           _Ty cube(_Ty n) {return square(n)*n;}

int n, e, t, m, a, b, c;
vector < vector < pair <int, int> > > graph;
vector <int> distances; //the value of each node i to the destination;

struct State {
	int x, c;
	State() {}
	State(int xx, int cc) {
		x = xx, c = cc;
	}
};

class Compare {
public:
	bool operator () (const State s1, const State s2) {
		return s1.c > s2.c;
	}
};

void dijkstra(int source, int sink = -1) {
	distances.clear();

	vector <bool> visited(graph.size(),false);
	distances.resize(graph.size(),oo);

	priority_queue <State, vector <State>, Compare> d;
	d.push(State(source, 0));
	distances[source] = 0;

	while (!d.empty()) {
		int cost = d.top().c;
		int indx = d.top().x;
		d.pop();

		if (visited[indx])
			continue;

		visited[indx] = true;

		if (indx == sink)
			return;

		foreach(i, graph[indx]) {
			int tempdist = cost + i->second;
			if (tempdist < distances[i->first]) {
				distances[i->first] = tempdist;
				d.push(State(i->first, tempdist));
			}
		}
	}
}

int main() {
	freopen("in.in", "rt", stdin);
	while (scanf("%d", &n) != EOF) {
		scanf("%d%d%d", &e, &t, &m);
		graph.resize(n);

		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			graph[b - 1].push_back(pair <int, int>(a - 1, c));
		}
		dijkstra(e - 1);

		int cnt = 0;
		for (int i = 0; i < sz(distances); i++)
			if (distances[i] <= t) ++cnt;

		printf("%d\n", cnt);
	}
	return 0;
}








