#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define SIZE(a) ((int)a.size())

int main() {
	for (int n; cin >> n && n;) {
		queue<short> cards, discarded;
		for (int i = 0; i < n; ++i) cards.push(i + 1);
		while (SIZE(cards) >= 2) {
			discarded.push(cards.front());
			cards.pop();
			cards.push(cards.front());
			cards.pop();
		}
		cout << "Discarded cards:";
		while (!discarded.empty()) {
			if (SIZE(discarded) == 1) {
				cout << " " << discarded.front();
			} else {
				cout << " " << discarded.front() << ",";
			}
			discarded.pop();
		}
		cout << endl;
		cout << "Remaining card: " << cards.front() << endl;
	}
	return 0;
}
