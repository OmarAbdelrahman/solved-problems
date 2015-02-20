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

#define                size(A)					    ((int)A.size())
#define                 All(A)					 A.begin(), A.end()
#define		  For(i, v, Limit)		for (int i = v; i < Limit; i++)
#define      DFor(i, Limit, v)     for (int i = Limit; i >= v; i--)
#define                    MAX									 31

typedef          long long int   						   LongInt;
typedef unsigned long long int 						      ULongInt;	
typedef            long double							LongDouble;

using namespace std;

int main()
{	
	char ch;
	int c, n;
	vector < pair <int, int> > num;
	string out;
	bool flag = false;

	scanf("%d", &c);
	while (c--)
	{
		if (flag) cout << endl;

		out = "";
		scanf("%d", &n);

		num.resize(n);
		For (i, 0, size(num))
			scanf("%d%d", &num[i].first, &num[i].second);

		int t;
		ch = '0';
		DFor(i, size(num) - 1, 0) {
			t = num[i].first + num[i].second + (ch - '0');
			if (t > 9) {
				ch = '1';
				out += (t % 10) + '0';
			} else {
				ch = '0';
				out += (t + '0');
			}
		}
		reverse(All(out));
		cout << out << endl;

		flag = true;
	}
	return 0;
}