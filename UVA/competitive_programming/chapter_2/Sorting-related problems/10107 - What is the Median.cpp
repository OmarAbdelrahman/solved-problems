#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int64;

int main() {
	vector<int64> data;
	for (int64 n; cin >> n;) {
		data.push_back(n);
		sort(data.begin(), data.end());
		int size = (int)data.size();
		int64 res;
		if (size & 1) {
			res = data[size >> 1];
		} else {
			int mid = size >> 1;
			res = (data[mid] + data[mid - 1]) >> 1;
		}
		cout << res << endl;
	}
	return 0;
}