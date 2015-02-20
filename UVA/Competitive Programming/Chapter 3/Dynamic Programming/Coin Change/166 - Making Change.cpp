#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

int const MAXV = 505;
int const MAXC = 6;
int const BIG_NUM = 0x3f3f3f3f;

int coins[] = { 5, 10, 20, 50, 100, 200 };

int ways[MAXV], total;
int amount[MAXV], value;
vector<int> available;
vector<vector<int> > cache;

void get_min(int &a, int b) {
	if (a > b) a = b;
}

int solve(int index, int sum) {
	if (sum < 0)
		return BIG_NUM;
	if (sum == 0)
		return 0;
	if (index == available.size())
		return sum == 0 ? 0 : BIG_NUM;
	if (cache[index][sum] != -1)
		return cache[index][sum];
	cache[index][sum] = BIG_NUM;
	get_min(cache[index][sum], solve(index, sum - available[index]) + 1);
	get_min(cache[index][sum], solve(index + 1, sum));
	return cache[index][sum];
}

int main(int argc, char **args) {
	fill(ways, ways + MAXV, BIG_NUM);
	ways[0] = 0;
	for (int i = 0; i < 6; ++i)
		for (int j = coins[i]; j < MAXV; ++j)
			ways[j] = min(ways[j], ways[j - coins[i]] + 1);
	while (true) {
		for (int i = 0; i < MAXC; ++i)
			cin >> amount[i];
		if (amount[0] + amount[1] + amount[2] + amount[3] + amount[4] + amount[5] == 0)
			break;
		double d; cin >> d;
		value = (int) ((d * 100) + 0.5);
		total = 0;
		available.clear();
		for (int i = 0; i < MAXC; ++i) {
			total += (coins[i] * amount[i]);
			for (int j = 0; j < amount[i]; ++j)
				available.push_back(coins[i]);
		}
		cache = vector<vector<int> >(available.size(), vector<int>(total + 5, -1));
		int result = BIG_NUM;
		for (int price = total; price >= value; --price)
			get_min(result, ways[price - value] + solve(0, price));
		printf("%3d\n", result);
	}
	return 0;
}