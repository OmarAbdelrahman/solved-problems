#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	for (int n; cin >> n;) {
		queue<int> q;
		priority_queue<int> p;
		stack<int> s;
		bool is_stack, is_queue, is_p_queue;
		is_stack = is_queue = is_p_queue = true;
		for (int a, b, i = 0; i < n; ++i) {
			cin >> a >> b;
			if (a == 1) {
				q.push(b);
				p.push(b);
				s.push(b);
			} else {
				is_stack &= !s.empty() && s.top() == b;
				is_queue &= !q.empty() && q.front() == b;
				is_p_queue &= !p.empty() && p.top() == b;
				if (!p.empty()) p.pop();
				if (!q.empty()) q.pop();
				if (!s.empty()) s.pop();
			}
		}
		if (is_stack + is_queue + is_p_queue > 1)
			puts("not sure");
		else if (is_stack)
			puts("stack");
		else if (is_queue)
			puts("queue");
		else if (is_p_queue)
			puts("priority queue");
		else
			puts("impossible");
	}
	return 0;
}