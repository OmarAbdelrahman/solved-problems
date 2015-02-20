#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define All(A) A.begin(), A.end()

int main() {
	int numberofNumbers;
	vector<int> numbers;
	while (cin >> numberofNumbers && numberofNumbers != 0) {
		numbers.resize(numberofNumbers);
		for (int i = 0; i < numberofNumbers; i++)
			cin >> numbers[i];
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numberofNumbers; i++)
			i == numberofNumbers - 1 ? cout << numbers[i] << endl : cout << numbers[i] << ' ';
	}
	return 0 ;
}