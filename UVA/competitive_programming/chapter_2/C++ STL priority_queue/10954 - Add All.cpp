#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>
#include <numeric>
#include <utility>

using namespace std;
typedef long long Int;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int length;
	while (cin >> length && length) {
		Int answer = 0, value = 0;
		priority_queue<Int, vector<Int>, greater<Int> > numbers;
		for (int turn = 0; turn < length; ++turn) {
			Int x; cin >> x;
			numbers.push(x);
		}
		while (numbers.size() != 1) {
			Int one = numbers.top(); numbers.pop();
			Int two = numbers.top(); numbers.pop();
			answer = (one + two);
			value += answer;
			numbers.push(answer);
		}
		cout << value << endl;
	}
	return 0;
}
