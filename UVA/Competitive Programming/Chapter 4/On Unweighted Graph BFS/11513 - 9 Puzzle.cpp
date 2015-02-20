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

struct state {
	state() {}
	state(string puzzle, string path) {
		this->puzzle = puzzle;
		this->path = path;
	}
	string puzzle;
	string path;
};

string to_string(int x) {
	stringstream sin; sin << x;
	return sin.str();
}

string horizontal(int row, string puzzle) {
	if (row == 0) {
		swap(puzzle[0], puzzle[1]);
		swap(puzzle[1], puzzle[2]);
	} else if (row == 1) {
		swap(puzzle[3], puzzle[4]);
		swap(puzzle[4], puzzle[5]);
	} else {
		swap(puzzle[6], puzzle[7]);
		swap(puzzle[7], puzzle[8]);
	}
	return puzzle;
}

string vertical(int col, string puzzle) {
	swap(puzzle[col + 0], puzzle[col + 3]);
	swap(puzzle[col + 0], puzzle[col + 6]);
	return puzzle;
}

map<string, string> build_graph(string src) {
	queue<state> q;
	map<string, string> answer;
	set<string> visited;
	visited.insert(src);
	answer[src] = "";
	for (q.push(state(src, "")); !q.empty(); q.pop()) {
		string puzzle = q.front().puzzle;
		string path = q.front().path;
		for (int i = 0; i < 3; ++i) {
			string p1 = horizontal(i, puzzle);
			string p2 = vertical(i, puzzle);
			if (visited.find(p1) == visited.end()) {
				visited.insert(p1);
				q.push(state(p1, "H" + to_string(i + 1) + path));
				answer[p1] = "H" + to_string(i + 1) + path;
			}
			if (visited.find(p2) == visited.end()) {
				visited.insert(p2);
				q.push(state(p2, "V" + to_string(i + 1) + path));
				answer[p2] = "V" + to_string(i + 1) + path;
			}
		}
	}
	return answer;
}

int main(int argc, char **args) {
	map<string, string> answer = build_graph("123456789");
	int puzzle[3][3];
	for (int value; scanf("%d", &value) && value;) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (i == 0 && j == 0) puzzle[i][j] = value; else scanf("%d", &puzzle[i][j]);
		string trg = "";
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				trg += to_string(puzzle[i][j]);
		if (answer.find(trg) == answer.end())
			puts("Not solvable");
		else {
			string result = answer[trg];
			if (result.length() == 0)
				puts("0");
			else
				cout << ((int) result.length() / 2) << " " << result << endl;
		}
	}
	return 0;
}