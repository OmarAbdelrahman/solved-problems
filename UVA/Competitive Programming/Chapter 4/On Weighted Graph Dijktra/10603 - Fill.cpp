#include <bits/stdc++.h>
using namespace std;

struct io {
	template<class T>
	static inline T next() {
		T x; std::cin >> x;
		return x;
	}
};

const int MAXL = 205;
const int INF = numeric_limits<int>::max() / 10;

struct state {
	int a, b, c;
	int cost;

	state() { }

	state(int a, int b, int c, int cost)
		: a(a), b(b), c(c), cost(cost) { }

	int smallest_amount_to(const int d) const {
		int result = INF;
		for (int v : { a, b, c })
			if (v <= d)
				result = min(result, d - v);
		return result;
	}

	bool operator < (const state& s) const {
		return cost > s.cost;
	}
};

void do_pour(int a, int b, int c, int poured, int cost, priority_queue<state>& q, map<pair<pair<int, int>, int>, int>& dist) {
	const pair<pair<int, int>, int> key = { { a, b }, c };
	const int new_cost = poured + cost;
	if (dist.find(key) == dist.end() || new_cost < dist[key]) {
		dist[key] = new_cost;
		q.push(state(a, b, c, new_cost));
	}
}

static pair<int, int> solve(int A, int B, int C, int d) {
	map<pair<pair<int, int>, int>, int> dist;
	dist[{ { 0, 0 }, C }] = 0;

	int d_dash = INF;
	int cost = 0;
	priority_queue<state> q;
	for (q.push(state(0, 0, C, 0)); !q.empty(); ) {
		const state s = q.top();
		q.pop();

		const int diff = s.smallest_amount_to(d);
		if (diff < d_dash) {
			d_dash = diff;
			cost = s.cost;
		}

		if (s.a == d || s.b == d || s.c == d)
			break;

		const int curr_cost = dist[{ { s.a, s.b }, s.c }];
		{
			const int pour = min(s.c, A - s.a);
			const int new_c = s.c - pour;
			const int new_a = s.a + pour;
			do_pour(new_a, s.b, new_c, pour, curr_cost, q, dist);
		}
		{
			const int pour = min(s.c, B - s.b);
			const int new_c = s.c - pour;
			const int new_b = s.b + pour;
			do_pour(s.a, new_b, new_c, pour, curr_cost, q, dist);
		}
		{
			const int pour = min(s.b, A - s.a);
			const int new_b = s.b - pour;
			const int new_a = s.a + pour;
			do_pour(new_a, new_b, s.c, pour, curr_cost, q, dist);
		}
		{
			const int pour = min(s.b, C - s.c);
			const int new_b = s.b - pour;
			const int new_c = s.c + pour;
			do_pour(s.a, new_b, new_c, pour, curr_cost, q, dist);
		}
		{
			const int pour = min(s.a, B - s.b);
			const int new_a = s.a - pour;
			const int new_b = s.b + pour;
			do_pour(new_a, new_b, s.c, pour, curr_cost, q, dist);
		}
		{
			const int pour = min(s.a, C - s.c);
			const int new_a = s.a - pour;
			const int new_c = s.c + pour;
			do_pour(new_a, s.b, new_c, pour, curr_cost, q, dist);
		}
	}

	return { cost, d - d_dash };
}

int main(int argc, char** args) {
	for (int TC = io::next<int>(); TC-- > 0; ) {
		const int a = io::next<int>();
		const int b = io::next<int>();
		const int c = io::next<int>();
		const int d = io::next<int>();
		const pair<int, int> result = solve(a, b, c, d);
		printf("%d %d\n", result.first, result.second);
	}
	return 0;
}
