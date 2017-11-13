#include <string>
#include <iostream>
using namespace std;

int main() {
	int counter = -1;
	string input, output;
	while (getline(cin, input)) {
		int n = (int)input.size();
		for (int i = 0; i < n; ++i) {
			if (input[i] == '"') {
				counter++;
				output += counter % 2 ? "''" : "``";
			} else {
				output += input[i];
			}
		}
		output += "\n";
	}
	cout << output;
	return 0;
}