#include <iostream>
#include <stdio.h>
using namespace std;

int const MAX = 155;
#define inf (1e7)
#define read(x) scanf("%d", &x);

int nodes, P, query;
int r[MAX];
int w[MAX][MAX][MAX];

int main(int argc, char **argv) {
	freopen("in.txt", "r", stdin);
	int T, i, j, k; read(T);
	for (int C = 1; T-- != 0; C++) {
		read(nodes);
		for (i = 0; i <= nodes; i++)
			for (j = 0; j <= nodes; j++)
				for (k = 0; k <= nodes; k++)
					w[i][j][k] = inf;
		for (i = 1; i < nodes; i++)
			for (j = i + 1; j <= nodes; j++) {
				read(w[0][i][j]);
				if (w[0][i][j] == -1) w[0][i][j] = inf;
				w[0][j][i] = w[0][i][j];
			}
		read(P);
		for (i = 1; i <= P; i++)
			read(r[i]);
		for (i = 1; i <= nodes; i++)
			w[0][i][i] = 0;
		for (k = 1; k <= P; k++)
			for (i = 1; i <= nodes; i++)
				for (j = 1; j <= nodes; j++)
					w[k][i][j] = min(w[k - 1][i][j], w[k - 1][i][r[k]] + w[k - 1][r[k]][j]);
		read(query);
		int f, t, res;
		printf("Case %d:", C);
		while (query-- != 0) {
			read(k);
			read(f);
			read(t);
			res = f == t ? 0 : w[k][f][t];
			printf(" %d", res == inf ? -1 : res);
		}
		puts("");
	}
	return 0;
}
