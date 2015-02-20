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

#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

struct DisjointSet {
	vector<int> parent;
	vector<int> rank;
	int numComponents;
	vector<int> setSize;

	DisjointSet(int n) {
		rank = vector<int>(n, 0);
		setSize = vector<int>(n, 1);
		parent = vector<int>(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
		numComponents = n;
	}

	int find(int setNum) {
		return setNum == parent[setNum] ? setNum : find(parent[setNum]);
	}

	bool equal(int s1, int s2) {
		return find(s1) == find(s2);
	}

	void join(int s1, int s2) {
		int p1 = find(s1);
		int p2 = find(s2);
		if (p1 == p2) return;
		if (rank[p1] == rank[p2])
			++rank[p1];
		if (rank[p1] < rank[p2])
			swap(p1, p2);
		parent[p2] = p1;
		setSize[p1] += setSize[p2];
		--numComponents;
	}
};

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int n, m; cin >> n >> m;) {
		if (n == 0 && m == 0)
			break;
		DisjointSet connection(n);
		set<int> groups;
		for (int i = 0; i < m; i++) {
			int k; cin >> k;
			int *now = new int[k];
			for (int j = 0; j < k; j++) {
				cin >> now[j];
				groups.insert(now[j]);
			}
			for (int a = 0; a < k; a++)
				for (int b = 0; b < k; b++)
					if (a != b)
						connection.join(now[a], now[b]);
		}
		int res = 0;
		FOREACH(group, groups)
			res += connection.equal(0, *group);
		if (res == 0) res = 1;
		cout << res << endl;
	}
	return 0;
}
