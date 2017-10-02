/*
ID: 1010
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	int boards, stalls, cows;
	scanf("%d%d%d", &boards, &stalls, &cows);
	vector<int> stall_numbers(cows);
	for (int i = 0; i < cows; ++i) {
		int t; scanf("%d", &t);
		stall_numbers[i] = t;
	}
	sort(stall_numbers.begin(), stall_numbers.end());
	vector<int> differences;
	for (int i = 0; i < cows - 1; ++i)
		differences.push_back(stall_numbers[i + 1] - stall_numbers[i] - 1);
	int m = 0, answer = stall_numbers[cows - 1] - stall_numbers[0];
	while (m < boards - 1) {
		int smallest = differences[0];
		vector<int>::iterator index = max_element(differences.begin(), differences.end());
		int index_value = index - differences.begin();
		answer -= differences[index_value];
		differences[index_value] = 0, ++m;
	}
	printf("%d\n", answer + 1);
	return 0;
}