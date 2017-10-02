/*
ID: 1010
PROG: fence
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <limits.h>
#include <map>
#include <math.h>
#include <set>
using namespace std;

#define MAX 1025

int circuit[MAX + 1];
vector<vector<int> > adjList;
int circuitPos;

void findCircuit(int node) {
	if (adjList[node].empty()) {
		circuit[circuitPos] = node;
		circuitPos++;
	} else {
		for (int i = 0; i < adjList[node].size(); ++i) {
			int nextNode = adjList[node][i];
			adjList[node].erase(adjList[node].begin() + i--);
			for (int j = 0; j < adjList[nextNode].size(); ++j)
				if (adjList[nextNode][j] == node) {
					adjList[nextNode].erase(adjList[nextNode].begin() + j--);
					break;
				}
			findCircuit(nextNode);
		}
		circuit[circuitPos] = node;
		circuitPos++;
	}
}

void findEulerCircuit() {
	circuitPos = 0;
	bool ok = false;
	for (int i = 0; i < adjList.size(); ++i)
		if (adjList[i].size() % 2) {
			findCircuit(i);
			ok = true;
			break;
		}
	if (!ok) findCircuit(0);
}

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int fences; cin >> fences;
	adjList = vector<vector<int> >(MAX);
	for (int i = 0; i < fences; ++i) {
		int a, b; cin >> a >> b;
		adjList[a - 1].push_back(b - 1);
		adjList[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < fences; ++i)
		sort(adjList[i].begin(), adjList[i].end());
	findEulerCircuit();
	for (int i = fences; i >= 0; --i)
		cout << circuit[i] + 1 << endl;
	return 0;
}