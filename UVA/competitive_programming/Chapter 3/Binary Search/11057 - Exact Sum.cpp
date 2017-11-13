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

#define sz(A) ((int)A.size())
#define res(A, n) A.resize(n)
#define	For(i, v, Limit) for (int i = v; i < Limit; i++)
#define	VC vector
#define VI VC <int>

using namespace std;

int main() {
	VI prices;
	int f, s;
	int _Minimum;
	int numberofBooks;
	int moneyAmount;
	while (cin >> numberofBooks) {
		res(prices, numberofBooks);
		For (i, 0, numberofBooks)
			cin >> prices[i];
		f = s = 0;
		cin >> moneyAmount;
		_Minimum = INT_MAX;
		For (i, 0, sz(prices))
			For (j, i + 1, sz(prices))
				if (prices[i] + prices[j] == moneyAmount) {
					if (abs(prices[i] - prices[j]) < _Minimum) {
						f = prices[i], s = prices[j];
						_Minimum = abs(prices[i] - prices[j]);
					}
				}
		if (f > s) swap(f, s);
		cout << "Peter should buy books whose prices are " << f << " and " << s << "." << endl << endl;
	}
	return 0;
}