#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	string input;
	int numberofcases;

	scanf("%d", &numberofcases);
	cin.ignore();
	for (int i = 0; i < numberofcases; i++) 
	{
		int total = 0;
		getline(cin, input);
		for (int j = 0; j < input.size(); j++) 
		{
			switch (input[j])
			{
			case 'a':
			case 'd':
			case 'g':
			case 'j':
			case 'm':
			case 'p':
			case 't':
			case 'w':
			case ' ':
				total++;
				break;

			case 'b':
			case 'e':
			case 'h':
			case 'k':
			case 'n':
			case 'q':
			case 'u':
			case 'x':
				total += 2;
				break;

			case 'c':
			case 'l':
			case 'f':
			case 'o':
			case 'i':
			case 'r':
			case 'v':
			case 'y':
				total += 3;
				break;

			case 's':
			case 'z':
				total += 4;
				break;

			default:
				break;
			}
		}
		printf("Case #%d: %d\n", i+1, total);
		input.clear();
	}

	return 0;
}