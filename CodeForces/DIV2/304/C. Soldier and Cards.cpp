#include <bits/stdc++.h>
using namespace std;

deque<int> get() {
	int k; cin >> k;
	deque<int> d(k);
	for (int& x : d) {
		cin >> x;
	}
	return d;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);

	int n; cin >> n;

	deque<int> q1 = get();
	deque<int> q2 = get();

	deque<int> a = q1;
	deque<int> b = q2;

	int count = 0;
	while (!q1.empty() && !q2.empty()) {
		int x1 = q1.front();
		q1.pop_front();
		int x2 = q2.front();
		q2.pop_front();

		if (x1 > x2) {
  		q1.push_back(x2);
			q1.push_back(x1);
		} else {
			q2.push_back(x1);
			q2.push_back(x2);
		}

		++count;
		if (count == 1000 || (q1 == a && q2 == b)) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << count << " " << (q1.empty() ? 2 : 1) << endl;
	return 0;
}
