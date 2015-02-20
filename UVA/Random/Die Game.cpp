#include <iostream>
#include <string>
using namespace std;

const string EAST = "east";
const string WEST = "west";
const string NORTH = "north";
const string SOUTH = "south";
const short g_sumOppositeFaces = 7;

int main()
{
	int numberOfCases;
	while (cin >> numberOfCases && numberOfCases != 0)
	{
		int top = 1;
		int west = 3, east = 4;
		int north = 2, south = 5;
		for (int i = 0; i < numberOfCases; i++)
		{
			string direction;

			cin >> direction;
			if (direction == NORTH)
			{
				north = top;
				top = south;
				south = g_sumOppositeFaces - north;
			}
			else if (direction == SOUTH)
			{
				south = top;
				top = north;
				north = g_sumOppositeFaces - south;
			}
			else if (direction == EAST)
			{
				east = top;
				top = west;
				west = g_sumOppositeFaces - east;
			}
			else if (direction == WEST)
			{
				west = top;
				top = east;
				east = g_sumOppositeFaces - west;
			}
		}
		cout << top << endl;
	}

	return 0;
}