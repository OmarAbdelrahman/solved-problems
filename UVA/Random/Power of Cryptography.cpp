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

int main() {
	long double n, p;
	while (cin >> n >> p) 
		cout << fixed << setprecision(0) << pow(p, 1 / n) << endl;
	return 0;
}