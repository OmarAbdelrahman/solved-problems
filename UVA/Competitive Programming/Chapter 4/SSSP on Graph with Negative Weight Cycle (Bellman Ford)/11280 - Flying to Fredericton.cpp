#include <bits/stdc++.h>
using namespace std;

struct io {
	template<class T>
	static inline T next() {
		T x; std::cin >> x;
		return x;
	}
};

const int M = 105;
const int INF = numeric_limits<int>::max() / 10;

int cost[M][M];
int dp[M][M];

void process(const vector<vector<int>>& g) {
	const int n = g.size();
	for (int i = 0; i < n; ++i)
		dp[i][0] = 0;

	for (int it = 1; it <= n; ++it)
		for (int v = 1; v < n; ++v) {
			dp[it][v] = dp[it - 1][v];
			for (int e : g[v]) {
				dp[it][v] = min(dp[it][v], dp[it - 1][e] + cost[v][e]);
			}
		}
}

int main(int argc, char** args) {
	int T = io::next<int>();
	for (int t = 1; T-- > 0; ++t) {
		if (t > 1) cout << endl;

		unordered_map<string, int> index;
		const int cities = io::next<int>();
		for (int i = 0; i < cities; ++i) {
			index[io::next<string>()] = cities - i - 1;
		}

		for (int i = 0; i < cities; ++i)
			for (int j = 0; j < cities; ++j) {
				cost[i][j] = INF;
				dp[i][j] = INF;
			}

		vector<vector<int>> g(cities);
		int roads = io::next<int>();
		while (roads-- > 0) {
			const int a = index[io::next<string>()];
			const int b = index[io::next<string>()];
			g[a].push_back(b);
			cost[a][b] = min(cost[a][b], io::next<int>());
		}

		process(g);

		cout << "Scenario #" << t << endl;
		for (int queries = io::next<int>(); queries-- > 0; ) {
			const int stopovers = io::next<int>() % cities;
			const int result = dp[stopovers + 1][cities - 1];
			if (result == INF)
				cout << "No satisfactory flights" << endl;
			else
				cout << "Total cost of flight(s) is $" << result << endl;
		}
	}
}
