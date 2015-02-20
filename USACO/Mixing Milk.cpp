/*
ID: 1010
PROG: milk
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

#define                size(A)					    ((int)A.size())
#define                 All(A)					 A.begin(), A.end()

using namespace std;

vector<pair<int,int> > farmers;

int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);

	int minimumPrice = 0;
	int collectedMilk = 0;
	int amountofMilkNeeded;
	int numberofFarmers;

	cin >> amountofMilkNeeded >> numberofFarmers;
	farmers.resize(numberofFarmers);

	for (int i = 0; i < size(farmers); i++)
		cin >> farmers[i].first >> farmers[i].second;

	sort(All(farmers));

	for (int i = 0; i < size(farmers); i++) 
	{
		collectedMilk += farmers[i].second;
		if (collectedMilk <= amountofMilkNeeded) 
		{
			minimumPrice += (farmers[i].first * farmers[i].second);
			if (collectedMilk == amountofMilkNeeded) break;
		} 
		else 
		{
			minimumPrice += (farmers[i].first * farmers[i].second);
			minimumPrice -= (farmers[i].first * (collectedMilk - amountofMilkNeeded));
			break;
		}
	}
	cout << minimumPrice << endl;

	return 0;
}