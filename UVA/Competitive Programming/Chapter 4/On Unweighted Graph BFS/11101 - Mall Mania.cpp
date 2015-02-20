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

int maxn, maxm;
int visited[2001][2001];

int solve(vector<pair<int, int> > &p1, vector<pair<int, int> > &p2) {
	queue<pair<pair<int, int>, int> > q;
	memset(visited, 0, sizeof(visited));
	if (p1.size() < p2.size()) {
		for (int i = 0; i < p1.size(); i++) {
			q.push(make_pair(make_pair(p1[i].first, p1[i].second), 0));
			visited[p1[i].first][p1[i].second] = 1;
		}
		for (int i = 0; i < p2.size(); i++)
			visited[p2[i].first][p2[i].second] = -1;
	} else {
		for (int i = 0; i < p2.size(); i++) {
			q.push(make_pair(make_pair(p2[i].first, p2[i].second), 0));
			visited[p2[i].first][p2[i].second] = 1;
		}
		for (int i = 0; i < p1.size(); i++)
			visited[p1[i].first][p1[i].second] = -1;
	}
	for (; !q.empty(); q.pop()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int c = q.front().second;
		if (visited[x][y] == -1)
			return c;
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
				if ((dx == 0) ^ (dy == 0)) {
					int nx = x + dx;
					int ny = y + dy;
					if (nx >= 0 && nx <= maxn && ny >= 0 && ny <= maxm)
						if (visited[nx][ny] != 1) {
							q.push(make_pair(make_pair(nx, ny), c + 1));
							if (visited[nx][ny] != -1)
								visited[nx][ny] = 1;
						}
				}
	}
	return -1;
}

int main(int argc, char **args) {
	for (int kim; scanf("%d", &kim) && kim;) {
		vector<pair<int, int> > p1(kim);
		for (int i = 0; i < kim; i++) {
			scanf("%d%d", &p1[i].first, &p1[i].second);
			maxn = max(maxn, p1[i].first);
			maxm = max(maxm, p1[i].second);
		}
		int pat; cin >> pat;
		vector<pair<int, int> > p2(pat);
		for (int i = 0; i < pat; i++) {
			scanf("%d%d", &p2[i].first, &p2[i].second);
			maxn = max(maxn, p2[i].first);
			maxm = max(maxm, p2[i].second);
		}
		printf("%d\n", solve(p1, p2));
	}
	return 0;
}