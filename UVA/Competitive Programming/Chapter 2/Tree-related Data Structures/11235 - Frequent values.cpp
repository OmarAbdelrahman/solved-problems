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

int const MAX = 100001 + 1;

class SegmentTree {
private:
	int rmq(int vertex, int L, int R, int i, int j) {
		if (i > R || j < L) return -1;
		if (i <= L && j >= R) return data[vertex];
		int p1 = rmq(2 * vertex, L, (L + R) / 2, i, j);
		int p2 = rmq(2 * vertex + 1, (L + R) / 2 + 1, R, i, j);
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return A[p1] >= A[p2] ? p1 : p2;
	}

	int update(int vertex, int L, int R, int index, int value) {
		int i = index;
		int j = index;
		if (i > R || j < L)
			return data[vertex];
		if (L == i && R == j) {
			A[i] = value;
			return data[vertex] = L;
		}
		int p1 = update(vertex * 2, L, (L + R) / 2, index, value);
		int p2 = update(vertex * 2 + 1, (L + R) / 2 + 1, R, index, value);
		return data[vertex] = A[p1] >= A[p2] ? p1 : p2;
	}

	void buildTree(int vertex, int L, int R) {
		if (L == R)
			data[vertex] = L;
		else {
			int leftNode = 2 * vertex;
			int rightNode = 2 * vertex + 1;
			buildTree(leftNode, L, (L + R) / 2);
			buildTree(rightNode, (L + R) / 2 + 1, R);
			int leftVal = A[data[leftNode]];
			int rightVal = A[data[rightNode]];
			data[vertex] = (leftVal >= rightVal) ? data[leftNode] : data[rightNode];
		}
	}

public:
	vector<int> data;
	vector<int> A;

	SegmentTree(int n) { initTree(n); }

	void initTree(int n) {
		A = vector<int>(n);
		int len = (int)(2 * pow(2.0, floor((log((double)A.size()) / log(2.0)) + 1)));
		data = vector<int>(len, 0);
	}

	void buildTree(int L, int R) {
		buildTree(1, 0, (int)A.size() - 1);
	}

	int rmq(int i, int j) {
		return rmq(1, 0, (int)A.size() - 1, i, j);
	}

	void update(int index, int newValue) {
		update(1, 0, (int)A.size() - 1, index, newValue);
	}
};

int main(int argc, char **argv) {
	int input[MAX];
	int freq[MAX];
	for (int n; cin >> n && n;) {
		int q; cin >> q;
		freq[0] = 1;
		map<int, int> end;
		for (int i = 0; i < n; i++) {
			cin >> input[i];
			if (i != 0) {
				if (input[i] == input[i - 1])
					freq[i] = freq[i - 1] + 1;
				else
					freq[i] = 1;
			}
			end[input[i]] = i;
		}
		SegmentTree tree(n);
		for (int i = 0; i < n; i++)
			tree.A[i] = freq[i];
		tree.buildTree(0, n - 1);
		for (int i = 0; i < q; i++) {
			int a, b; cin >> a >> b;
			--a, --b;
			int res = 0;
			if (a == 0 && b == n - 1)
				res = tree.A[tree.rmq(a, b)];
			else if (input[a] == input[b])
				res = b - a + 1;
			else {
				res = end[input[a]] - a + 1;
				res = max(res, tree.A[tree.rmq(end[input[a]] + 1, b)]);
			}
			cout << res << endl;
		}
	}
	return 0;
}
