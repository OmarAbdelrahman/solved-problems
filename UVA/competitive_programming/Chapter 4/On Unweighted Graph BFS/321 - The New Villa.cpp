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

int const MAX = 12;
vector<int> edge[MAX];
vector<int> light[MAX];
bool visited[MAX][1 << MAX];

struct state {
	int index, mask;
	vector<string> steps;
	state() {}
	state(int i, int m, vector<string> s)
		: index(i), mask(m), steps(s) {}
};

string to_string(int n) {
	stringstream sin; sin << n;
	return sin.str();
}

pair<int, vector<string> > solve(int rooms) {
	queue<state> q;
	visited[0][1] = true;
	for (q.push(state(0, 1, vector<string>())); !q.empty(); q.pop()) {
		int index = q.front().index;
		int mask = q.front().mask;
		vector<string> steps = q.front().steps;
		if (index == rooms - 1 && mask == (1 << (rooms - 1)))
			return make_pair(1, steps);
		for (int i = 0; i < light[index].size(); i++) {
			int lamp = light[index][i];
			if (mask & (1 << lamp)) {
				if (!visited[index][mask ^ (1 << lamp)] && index != lamp) {
					visited[index][mask ^ (1 << lamp)] = true;
					steps.push_back("Switch off light in room " + to_string(lamp + 1) + ".");
					q.push(state(index, mask ^ (1 << lamp), steps));
					steps.erase(--steps.end());
				}
			} else {
				if (!visited[index][mask ^ (1 << lamp)]) {
					visited[index][mask ^ (1 << lamp)] = true;
					steps.push_back("Switch on light in room " + to_string(lamp + 1) + ".");
					q.push(state(index, mask ^ (1 << lamp), steps));
					steps.erase(--steps.end());
				}
			}
		}
		for (int i = 0; i < edge[index].size(); i++) {
			int room = edge[index][i];
			if (mask & (1 << room)) {
				if (!visited[room][mask]) {
					visited[room][mask] = true;
					steps.push_back("Move to room " + to_string(room + 1) + ".");
					q.push(state(room, mask, steps));
					steps.erase(--steps.end());
				}
			}
		}
	}
	return make_pair(-1, vector<string>());
}

int main(int argc, char **argv) {
	int rooms, doors, switches;
	for (int turn = 1; cin >> rooms >> doors >> switches; turn++) {
		if (rooms + doors + switches == 0)
			break;
		for (int i = 0; i < MAX; i++) {
			light[i].clear();
			edge[i].clear();
		}
		for (int i = 0; i < doors; i++) {
			int a, b; cin >> a >> b;
			edge[a - 1].push_back(b - 1);
			edge[b - 1].push_back(a - 1);
		}
		for (int i = 0; i < switches; i++) {
			int a, b; cin >> a >> b;
			light[a - 1].push_back(b - 1);
		}
		memset(visited, false, sizeof(visited));
		pair<int, vector<string>> result = solve(rooms);
		printf("Villa #%d\n", turn);
		if (result.first == -1) {
			puts("The problem cannot be solved.");
		} else {
			printf("The problem can be solved in %d steps:\n", (int) result.second.size());
			for (int i = 0; i < result.second.size(); i++)
				cout << "- " << result.second[i] << endl;
		}
		cout << endl;
	}
	return 0;
}