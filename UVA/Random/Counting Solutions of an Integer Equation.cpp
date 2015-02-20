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
using namespace std;

int main()
{
	long long c;
	int n , z, i;
	while(cin >> n)
	{
		c = 0;
		i = (!(n % 2)) ? 0 : 1;
		for (int x = start; x <= n; x += 2)
			c += ((n - x) / 2) + 1;
		cout << c << endl;
	}
	return 0;
}