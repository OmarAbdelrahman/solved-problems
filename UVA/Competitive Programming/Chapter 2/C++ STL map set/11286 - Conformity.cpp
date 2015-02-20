#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

#define SIZE(a) ((int)a.size())
#define FOREACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

int main() {
	for (int n; cin >> n && n;) {
		map<vector<int>, int> m;
		vector<int> v(5);
		vector<vector<int> > vs;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 5; ++j)
				cin >> v[j];
			sort(v.begin(), v.end());
			vs.push_back(v);
			m[v]++;
		}
		int res = 0;
		FOREACH(data, m) res = max(res, data->second);
		int cnt = 0;
		FOREACH(vv, vs) cnt += m[*vv] == res;
		printf("%d\n", cnt);
	}
	return 0;
}