#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;

#define LENGTH(s) ((int)s.length())
#define SIZE(s) ((int)s.size())
int const MAX = 10000 + 5;

int matrix[MAX][MAX];

int main() {
	for (int rows, cols; scanf("%d%d", &rows, &cols) != EOF;) {
		memset(matrix, 0, sizeof(matrix));
		for (int r = 0; r < rows; ++r) {;
			int n; scanf("%d", &n);
			if (!n) continue;
			vector<int> positions(n);
			vector<int> values(n);
			for (int i = 0; i < n; ++i)
				scanf("%d", &positions[i]);
			for (int i = 0; i < n; ++i)
				scanf("%d", &values[i]);
			for (int i = 0; i < SIZE(values); ++i) {
				matrix[r][positions[i] - 1] = values[i];
			}
		}
		printf("%d %d\n", cols, rows);
		for (int c = 0; c < cols; ++c) {
			int cnt = 0;
			vector<int> positions;
			for (int r = 0; r < rows; ++r)
				if (matrix[r][c] != 0) {
					++cnt;
					positions.push_back(r);
				}
			int size = SIZE(positions);
			printf("%d", cnt);
			if (cnt == 0) {
				printf("\n\n");
				continue;
			}
			for (int i = 0; i < size; ++i)
				printf(" %d", positions[i] + 1);
			printf("\n");
			for (int i = 0; i < size; ++i) {
				if (i + 1 == size)
					printf("%d\n", matrix[positions[i]][c]);
				else
					printf("%d ", matrix[positions[i]][c]);
			}
		}
	}
	return 0;
}