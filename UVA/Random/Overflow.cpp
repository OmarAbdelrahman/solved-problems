#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	char operation;
	long double result;
	string numberInString;
	pair <long double, long double> numbers;

	while (getline(cin, numberInString))
	{
		cout << numberInString << endl;
		
		istringstream stream(numberInString);
		stream >> numbers.first >> operation >> numbers.second;

		switch (operation)
		{
		case '+': result = numbers.first + numbers.second; break;
		case '*': result = numbers.first * numbers.second; break;
		}

		if (numbers.first > INT_MAX && numbers.second > INT_MAX)
		{
			puts("first number too big");
			puts("second number too big");
			puts("result too big");
		}
		else if (numbers.first > INT_MAX && result > INT_MAX)
		{
			puts("first number too big");
			puts("result too big");
		}
		else if (numbers.second > INT_MAX && result > INT_MAX)
		{
			puts("second number too big");
			puts("result too big");
		}
		else if (numbers.first > INT_MAX)
		{
			puts("first number too big");
		}
		else if (numbers.second > INT_MAX)
		{
			puts("second number too big");
		}
		else if (result > INT_MAX)
		{
			puts("result too big");
		}
	}

	return 0;
}