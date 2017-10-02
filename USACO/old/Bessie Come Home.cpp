/*
ID: 1010
PROG: comehome
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define max_t 1000000
#define sz(a) ((int)a.size())

int size;
typedef vector<int> edge_t;
typedef vector<edge_t> adjacent_matrix;
adjacent_matrix list;
bool has_cow[60];
char pasture;

int main() {
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	scanf("%d", &size);
	list = adjacent_matrix(60, edge_t(60, max_t));
	for (int i = 0; i < size; ++i) {
		char a, b; int cost;
		cin >> a >> b >> cost;
		if (isupper(a) && a != 'Z')
			has_cow[a - 'A'] = true;
		if (isupper(b) && b != 'Z')
			has_cow[b - 'A'] = true;
		if (cost < list[a - 'A'][b - 'A'])
			list[a - 'A'][b - 'A'] = cost;
		if (cost < list[b - 'A'][a - 'A'])
			list[b - 'A'][a - 'A'] = cost;
	}
	for (int k = 0; k < 60; ++k)
		for (int i = 0; i < 60; ++i)
			for (int j = 0; j < 60; ++j)
				list[i][j] = min(list[i][j], list[i][k] + list[k][j]);
	int answer = max_t;
	for (char i = 'A'; i <= 'Z'; ++i)
		if (has_cow[i - 'A'] && list[i - 'A']['Z' - 'A'] < answer)
			answer = list[i - 'A']['Z' - 'A'], pasture = i;
	cout << pasture << " " << answer << endl;
	return 0;
}