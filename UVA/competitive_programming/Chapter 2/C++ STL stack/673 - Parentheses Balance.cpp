#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int numberOfCases;
	cin >> numberOfCases;
	cin.ignore();
	for (int i = 0; i < numberOfCases; i++) {
		string sentence;
		stack<char> parenthesis;
		getline(cin, sentence);
		if (sentence.size() == 1 || sentence.size() % 2 != 0) {
			puts("No");
			continue;
		}
		for (int j = 0; j < sentence.size(); j++) {
			if (sentence[j] == '(' || sentence[j] == '[')
				parenthesis.push(sentence[j]);
			else if (sentence[j] == ')') {
				if (!parenthesis.empty())
					if (parenthesis.top() == '(')
						parenthesis.pop();
			} else if (sentence[j] == ']') {
				if (!parenthesis.empty())
					if (parenthesis.top() == '[')
						parenthesis.pop();
			}
		}
		if (parenthesis.empty()) 
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}