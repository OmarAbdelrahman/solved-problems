#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Size(A) ((int)A.size())

int main() {
	int numberofcases;
	vector<int> numbers_toEnter;
	vector<int> absolute_values;
	while (cin >> numberofcases) {
		bool check = true;
		numbers_toEnter.resize(numberofcases);
		absolute_values.resize(numberofcases - 1);
		for (int i = 0; i < numberofcases; i++)
			cin >> numbers_toEnter[i];
		if (Size(numbers_toEnter) == 1) {
			puts("Jolly");
			continue;
		}
		for (int i = 0; i < Size(numbers_toEnter) - 1; i++)
			absolute_values[i] = abs(numbers_toEnter[i] - numbers_toEnter[i + 1]);
		sort(absolute_values.begin(), absolute_values.end());
		for (int i = 0; i < Size(absolute_values); i++)
			if (absolute_values[i] != i + 1) {
				check = false;
				break;
			}
		if (check)
			puts("Jolly");
		else
			puts("Not jolly");
	}
	return 0;
}