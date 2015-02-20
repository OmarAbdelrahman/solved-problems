#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

int const MAXS = 205;
double const METRO = 40.0;
double const WALK = 10.0;

struct io_utilis {
	template<class T> static T next() {
		T n; std::cin >> n;
		return n;
	}

	static std::string next_line() {
		std::string s; std::getline(std::cin, s);
		return s;
	}
};

struct integer_utilis {
	static int round(double x) {
		int ret = x;
		ret += (x - double(int(x)) >= 0.5);
		return ret;
	}
};

struct state {
	int x, y;
	state() {}
	state(int _x, int _y)
		: x(_x), y(_y) {}
	friend istream& operator >> (istream& sin, state& s) {
		sin >> s.x >> s.y;
		return sin;
	}
	bool operator < (const state& s) const {
		if (x != s.x)
			return x < s.x;
		return y < s.y;
	}
};

struct vertex {
	int index;
	double cost;
	vertex() {}
	vertex(int i, double c)
		: index(i), cost(c) {}
	bool operator < (const vertex& v) const {
		return cost > v.cost;
	}
};

map<state, int> value;
vector<vertex> G[MAXS];

static double time_cost(state a, state b, double velocity) {
	return hypot((double) (a.x - b.x), (double) (a.y - b.y)) * 60.0 / (velocity * 1000.0);
}

static vector<state> parse(string data) {
	stringstream sin(data);
	vector<state> answer;
	for (state s; sin >> s && s.x != -1;)
		answer.push_back(s);
	return answer;
}

static void initialize_all() {
	value.clear();
	for (int i = 0; i < MAXS; ++i)
		G[i].clear();
}

static int solve(int src, int trg) {
	priority_queue<vertex> q;
	vector<bool> visited(value.size(), false);
	vector<double> distance(value.size(), (double) INT_MAX);
	for (q.push(vertex(src, 0.0)), distance[src] = 0.0; !q.empty();) {
		int curr = q.top().index;
		double cost = q.top().cost;
		q.pop();
		if (curr == trg)
			return integer_utilis::round(cost);
		if (visited[curr])
			continue;
		visited[curr] = true;
		for (int i = 0; i < G[curr].size(); ++i) {
			vertex next = G[curr][i];
			if (cost + next.cost < distance[next.index]) {
				distance[next.index] = cost + next.cost;
				q.push(vertex(next.index, cost + next.cost));
			}
		}
	}
	return integer_utilis::round(distance[trg]);
}

int main(int argc, char **args) {
	int TC = io_utilis::next<int>();
	while (TC-- > 0) {
		int cur_index = 0;
		initialize_all();
		state home = io_utilis::next<state>();
		state school = io_utilis::next<state>();
		value[home] = cur_index++;
		value[school] = cur_index++;
		G[0].push_back(vertex(1, time_cost(home, school, WALK)));
		G[1].push_back(vertex(0, time_cost(home, school, WALK)));
		cin.ignore();
		vector<vector<state> > subway;
		for (string info; (info = io_utilis::next_line()) != "";) {
			subway.push_back(parse(info));
			int last = subway.size() - 1;
			for (int i = 0; i < subway[last].size(); ++i)
				value[subway[last][i]] = cur_index++;
			for (int i = 0; i < subway[last].size(); ++i) {
				int a = value[subway[last][i]];
				G[0].push_back(vertex(a, time_cost(home, subway[last][i], WALK)));
				G[a].push_back(vertex(0, time_cost(home, subway[last][i], WALK)));
				G[1].push_back(vertex(a, time_cost(school, subway[last][i], WALK)));
				G[a].push_back(vertex(1, time_cost(school, subway[last][i], WALK)));
				if (i + 1 < subway[last].size()) {
					int b = value[subway[last][i + 1]];
					G[a].push_back(vertex(b, time_cost(subway[last][i], subway[last][i + 1], METRO)));
					G[b].push_back(vertex(a, time_cost(subway[last][i], subway[last][i + 1], METRO)));
				}
				if (i - 1 >= 0) {
					int b = value[subway[last][i - 1]];
					G[a].push_back(vertex(b, time_cost(subway[last][i], subway[last][i - 1], METRO)));
					G[b].push_back(vertex(a, time_cost(subway[last][i], subway[last][i - 1], METRO)));
				}
				if (subway.size() > 1) {
					for (int j = 0; j < subway[last - 1].size(); ++j) {
						int b = value[subway[last - 1][j]];
						G[a].push_back(vertex(b, time_cost(subway[last][i], subway[last - 1][j], WALK)));
						G[b].push_back(vertex(a, time_cost(subway[last][i], subway[last - 1][j], WALK)));
					}
				}
			}
		}
		for (map<state, int>::iterator i = value.begin(); i != value.end(); i++)
			for (map<state, int>::iterator j = value.begin(); j != value.end(); j++)
				if (i->second != j->second)
					G[i->second].push_back(vertex(j->second, time_cost(i->first, j->first, WALK)));
		printf("%d\n", solve(0, 1));
		if (TC > 0)
			printf("\n");
	}
	return 0;
}