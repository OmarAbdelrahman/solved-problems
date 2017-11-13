#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

void GetMarblePosition(int numberofMarble, vector<int>& marbles)
{
	for (int i = 0; i < marbles.size(); i++)
		if (numberofMarble == marbles[i])
		{
			printf("%d found at %d\n", numberofMarble, i + 1);
			return;
		}
	printf("%d not found\n", numberofMarble);
}

int main()
{
	int numberofMarbles;
	int numberofQueries;
	vector<int> marbles;
	vector<int> queries;
	for (int caseNumber = 1; cin >> numberofMarbles >> numberofQueries; caseNumber++)
	{
		if (numberofMarbles == 0 && numberofQueries == 0)
			break;

		marbles.resize(numberofMarbles);
		for (int i = 0; i < marbles.size(); i++)
			cin >> marbles[i];

		queries.resize(numberofQueries);
		for (int i = 0; i < queries.size(); i++)
			cin >> queries[i];

		printf("CASE# %d:\n", caseNumber);
		sort(marbles.begin(), marbles.end());

		for (int i = 0; i < queries.size(); i++)
			GetMarblePosition(queries[i], marbles);
	}
	return 0;
}