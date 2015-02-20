#include <iostream>
#include <vector>
using namespace std;

int main() {
	int numberOfElements;
	while (cin >> numberOfElements) {
		int moves = 0;
		vector<int> elements(numberOfElements);
		for (int i = 0; i < numberOfElements; i++)
			cin >> elements[i];
		for (int i = 0; i < numberOfElements - 1; i++)
			for (int j = i + 1; j < numberOfElements; j++)
				if (elements[i] > elements[j])
					moves++;
		printf("Minimum exchange operations : %d\n", moves);
	}
	return 0;
}