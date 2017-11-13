#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

#define size(A) ((int)A.size())

void backTrack(vector<int> &p_numbers, vector<int> &p_toDisplay, int index, int level)
{
	if (index == size(p_toDisplay)) 
	{
		for (int i = 0; i < size(p_toDisplay); i++)
		{
			if (i != size(p_toDisplay) - 1) cout << p_toDisplay[i] << ' ';
			else cout << p_toDisplay[i] << endl;
		}
	}
	else for (int i = level; i < size(p_numbers); i++) 
	{
		p_toDisplay[index] = p_numbers[i];
		backTrack(p_numbers, p_toDisplay, index + 1, i + 1);
	}
}

int main()
{
	int numbersToEnter;
	int numberOfNumbers;
	vector<int> enteredNumbers;
	vector<int> toDisplay(6);
	for (int turn = 0; cin >> numberOfNumbers && numberOfNumbers != 0; turn++)
	{
		if (turn) cout << endl;
		enteredNumbers.resize(numberOfNumbers);
		for (int i = 0; i < numberOfNumbers; i++)
		{
			scanf("%d", &numbersToEnter);
			enteredNumbers[i] = numbersToEnter;
		}
		backTrack(enteredNumbers, toDisplay, 0, 0);
	}
	return 0;
}