/*
ID: 1010
PROG: milk3
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;

int const sz = 21;
bool vis[sz][sz][sz];
set<int> s;
int A, B, C;

pair<int, int> pour(int to, int from, int cap) {
	while (from && to < cap)
		++to, --from;
	return make_pair(to, from);
}

void solve(int a, int b, int c) {
	if (a < 0 || a > A || b < 0 || b > B || c < 0 || c > C)
		return;
	if (vis[a][b][c])
		return;
	vis[a][b][c] = true;
	if (!a) s.insert(c);
	pair<int, int> milk;
	milk = pour(a, c, A);
	solve(milk.first, b, milk.second);
	milk = pour(b, c, B); 
	solve(a, milk.first, milk.second);
	milk = pour(b, a, B); 
	solve(milk.second, milk.first, c);
	milk = pour(c, a, C);
	solve(milk.second, b, milk.first);
	milk = pour(a, b, A); 
	solve(milk.first, milk.second, c);
	milk = pour(c, b, C); 
	solve(a, milk.second, milk.first);
}

int main() {
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	scanf("%d%d%d", &A, &B, &C);
	solve(0, 0, C);
	ostringstream oss;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		oss << *it << " ";
	cout << oss.str().substr(0, oss.str().size() - 1) << endl;
	return 0;
}