/*
ID: 1010
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	int number_ofPeople;
	vector<pair<string, int> > Group;
	for (int n = 0; cin >> number_ofPeople; n++)
	{
		if (n) cout << endl;
		Group.resize(number_ofPeople);
		for (int i = 0; i < number_ofPeople; i++)
		{
			cin >> Group[i].first;
			Group[i].second = 0;
		}
		string name;
		int pplNumber;
		int moneyPaid;
		for (int i = 0; i < number_ofPeople; i++)
		{
			cin >> name >> moneyPaid >> pplNumber;
			if (pplNumber == 0) continue;
			string tempName;
			int temp = moneyPaid / pplNumber;
			for (int j = 0; j < Group.size(); j++)
				if (Group[j].first == name)
				{
					Group[j].second -= (temp * pplNumber);
					break;
				}
			for (int j = 0; j < pplNumber; j++)
			{
				cin >> tempName;
				for (int k = 0; k < Group.size(); k++)
					if (Group[k].first == tempName)
					{
						Group[k].second += temp;
						break;
					}
			}
		}
		for (int i = 0; i < Group.size(); i++)
			cout << Group[i].first << ' ' << Group[i].second << endl;
		Group.clear();
	}
	return 0;
}