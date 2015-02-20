/*
ID: 1010
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
#include <bitset>
#include <complex>
#include <cassert>
#include <numeric>

using namespace std;

#define L 1000000000

template <class _Ty> inline _Ty sqr(_Ty n) 
{
	return n * n;
}

template <class _Ty> inline _Ty cube(_Ty n)
{
	return sqr(n) * n;
}

int main()
{
	vector<int> v1, v2, v3(100);
	for (int i = 1; sqr(i) < L; i++) v1.push_back(sqr(i));
	for (int i = 1; cube(i) < L; i++) v2.push_back(cube(i));
	vector <int>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	v3.resize(int(it - v3.begin()));
	int a, b;
	while (cin >> a >> b) {
		int cnt = 0;
		for (int i = 0; i < v3.size(); i++)
			if (v3[i] >= a && v3[i] <= b) ++cnt;
		cout << cnt << endl;
	}
	return 0;
}