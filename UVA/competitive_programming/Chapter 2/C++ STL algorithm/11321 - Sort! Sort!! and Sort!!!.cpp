#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int64;

struct Number {
	int64 n;
	int mod;
	bool even;
};

int64 n, m;
Number data[10000 + 5];

bool operator < (Number n1, Number n2) {
	if (n1.mod != n2.mod)
		return n1.mod < n2.mod;
	if (!n1.even && n2.even) return true;
	if (!n1.even && !n2.even && n1.n > n2.n) return true;
	if (n1.even && n2.even && n1.n < n2.n) return true;
	return false;
}

int main() {
	while (cin >> n >> m) {
		cout << n << " " << m << endl;
		if (!n && !m) break;
		for (int i = 0; i < n; ++i) {
			cin >> data[i].n;
			int ab = data[i].n < 0 ? -data[i].n : data[i].n;
			if (ab % 2) {
				data[i].even = false;
			} else {
				data[i].even = true;
			}
			data[i].mod = (int)data[i].n % m;
		}
		sort(data, data + n);
		for (int i = 0; i < n; ++i)
			cout << data[i].n << endl;
	}
	return 0;
}