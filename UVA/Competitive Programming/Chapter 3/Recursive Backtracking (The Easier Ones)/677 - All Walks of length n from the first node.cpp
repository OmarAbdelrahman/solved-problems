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

int walkLen, nodes;
bool connected[15][15];
bool visited[15];
int cnt;

void printWalks(int start, vector<int> walk) {
	if (walk.size() == walkLen) {
		++cnt;
		printf("(1");
		for (int i = 0; i < walkLen; ++i)
			printf(",%d", walk[i] + 1);
		puts(")");
	} else {
		for (int i = 0; i < nodes; ++i)
			if (connected[start][i] && !visited[i]) {
				visited[i] = true;
				walk.push_back(i);
				printWalks(i, walk);
				walk.pop_back();
				visited[i] = false;
			}
	}
}

int main() {
	bool first = true;
	while (scanf("%d%d", &nodes, &walkLen) != EOF) {
		if (!first) puts("");
		cnt = 0;
		memset(connected, false, sizeof(connected));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < nodes; ++i)
			for (int j = 0; j < nodes; ++j) {
				int a; scanf("%d", &a);
				connected[i][j] = a == 1;
			}
		vector<int> res;
		visited[0] = true;
		printWalks(0, res);
		if (cnt == 0)
			printf("no walk of length %d\n", walkLen);
		int temp; scanf("%d", &temp);
		first = false;
	}
	return 0;
}