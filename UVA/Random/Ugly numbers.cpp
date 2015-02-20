#include <iostream>
#include <set>
using namespace std;

int main()
{
	set <int> numbers;
	numbers.insert(1);

	set <int>::iterator it = numbers.begin();

	for (int i = 0; i != 1500 - 1; i++, it++)
	{
		numbers.insert((*it) * 2);
		numbers.insert((*it) * 3);
		numbers.insert((*it) * 5);
	}
	cout << "The 1500'th ugly number is " << *it << "." << endl;
	
	return 0;
}