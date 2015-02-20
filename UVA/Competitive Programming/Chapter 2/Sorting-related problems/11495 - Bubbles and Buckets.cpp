#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long int64;
#define SIZE(a) ((int)a.size())

int64 cnt;

vector<int64> merge(vector<int64>& L, vector<int64>& R) {
	vector<int64> res;
	int LI = 0, RI = 0;
	while (LI < SIZE(L) && RI < SIZE(R)) {
		if (L[LI] < R[RI]) {
			res.push_back(L[LI++]);
		} else {
			res.push_back(R[RI++]);
			cnt += (SIZE(L) - LI);
		}
	}
	while (LI < SIZE(L))
		res.push_back(L[LI++]);
	while (RI < SIZE(R))
		res.push_back(R[RI++]);
	return res;
}

vector<int64> merge_sort(vector<int64>& A) {
	vector<int64> res, L, R;
	if (SIZE(A) <= 1) return A;
	int M = SIZE(A) >> 1;
	for (int i = 0; i < M; ++i)
		L.push_back(A[i]);
	for (int i = M; i < SIZE(A); ++i)
		R.push_back(A[i]);
	L = merge_sort(L), R = merge_sort(R);
	res = merge(L, R);
	return res;
}

int main() {
	for (int size; cin >> size && size;) {
		cnt = 0;
		vector<int64> data(size);
		for (int i = 0; i < size; ++i)
			cin >> data[i];
		vector<int64> sorted_data = merge_sort(data);
		cout << ((cnt & 1) ?  "Marcelo" : "Carlos") << endl;
	}
	return 0;
}
