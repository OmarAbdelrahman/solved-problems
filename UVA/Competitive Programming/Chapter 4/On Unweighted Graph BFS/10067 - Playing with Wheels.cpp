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

using namespace std;

#define MAX 10

struct State {
	int w;
	int x;
	int y;
	int z;
	int c;
};

State src;
State trg;

int W[] = {-1, 1, 0, 0, 0, 0, 0, 0};
int X[] = {0, 0, -1, 1, 0, 0, 0, 0};
int Y[] = {0, 0, 0, 0, -1, 1, 0, 0};
int Z[] = {0, 0, 0, 0, 0, 0, -1, 1};

vector<State> bad;
bool visited[MAX][MAX][MAX][MAX];

void checkValues(State &p_next) {
	if (p_next.w == 10) p_next.w = 0;
	if (p_next.x == 10) p_next.x = 0;
	if (p_next.y == 10) p_next.y = 0;
	if (p_next.z == 10) p_next.z = 0;
	if (p_next.w == -1) p_next.w = 9;
	if (p_next.x == -1) p_next.x = 9;
	if (p_next.y == -1) p_next.y = 9;
	if (p_next.z == -1) p_next.z = 9;
}

int getMinimum() {
	queue<State> BFS;
	BFS.push(src);
	visited[src.w][src.x][src.y][src.z] = true;
	while (!BFS.empty()) {
		State cur = BFS.front();
		BFS.pop();
		if (cur.w == trg.w && cur.x == trg.x && cur.y == trg.y && cur.z == trg.z)
			return cur.c;
		for (int i = 0; i < 8; i++) {
			State nextState = {cur.w + W[i], cur.x + X[i], cur.y + Y[i], cur.z + Z[i], cur.c + 1};
			checkValues(nextState);
			if (!visited[nextState.w][nextState.x][nextState.y][nextState.z]) {
				BFS.push(nextState);
				visited[nextState.w][nextState.x][nextState.y][nextState.z] = true;
			}
		}
	}
	return -1;
}

int main() {
	int badNumber;
	int T; scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d%d%d", &src.w, &src.x, &src.y, &src.z);
		scanf("%d%d%d%d", &trg.w, &trg.x, &trg.y, &trg.z);
		scanf("%d", &badNumber);
		src.c = 0;
		memset(visited, false, sizeof(visited));
		bad.resize(badNumber);
		for (int j = 0; j < bad.size(); j++) {
			cin >> bad[j].w >> bad[j].x >> bad[j].y >> bad[j].z;
			visited[bad[j].w][bad[j].x][bad[j].y][bad[j].z] = true;
		}
		cout << getMinimum() << endl;		
	}
	return 0;
}