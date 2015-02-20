#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
#include <limits.h>
using namespace std;

#define size(A) ((int)A.size())

int x[] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int y[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

string toInsertOne;
string toInsertTwo;
int counterOne = 0;
int counterTwo = 0;
bool flag = false;

set<string> first;
set<string> second;
vector<string> toPrint;
set<string>::iterator it;

char boardOne[4][4];
char boardTwo[4][4];
bool visitedOne[4][4];
bool visitedTwo[4][4];

bool IsVowel(char ch) {
	return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y');
}

bool IsAvailable(int i, int j) {
	return (i >= 0 && j >= 0 && i < 4 && j < 4);
}

void GetCombination(int row, int col, int index = 0) {
	if (index == 3) {
		counterOne = counterTwo = 0;
		for (int i = 0; i < size(toInsertOne); i++) {
			if (IsVowel(toInsertOne[i])) counterOne++;
			if (IsVowel(toInsertTwo[i])) counterTwo++;
		}
		if (counterOne == 2) first.insert(toInsertOne);
		if (counterTwo == 2) second.insert(toInsertTwo);
	} else for (int i = 0; i < 8; i++) {
		if (IsAvailable(row + x[i], col + y[i]))
			if (!visitedOne[row + x[i]][col + y[i]]) {
				visitedOne[row + x[i]][col + y[i]] = visitedTwo[row + x[i]][col + y[i]] = true;
				toInsertOne += boardOne[row + x[i]][col + y[i]];
				toInsertTwo += boardTwo[row + x[i]][col + y[i]];
				GetCombination(row + x[i], col + y[i], index + 1);
				toInsertOne.erase(size(toInsertOne) - 1, 1);
				toInsertTwo.erase(size(toInsertTwo) - 1, 1);
				visitedOne[row + x[i]][col + y[i]] = visitedTwo[row + x[i]][col + y[i]] = false;
			}
	}
}

int main() {
	while (true) {
		char character;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 8; j++) {
				cin >> character;
				if (character == '#') exit(0);
				(j < 4) ? boardOne[i][j] = character : boardTwo[i][j - 4] = character;
			}
		if (flag) cout << endl;
		memset(visitedOne, false, sizeof(bool) * 4 * 4);
		memset(visitedTwo, false, sizeof(bool) * 4 * 4);
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++) {
				toInsertOne = toInsertTwo = "";
				toInsertOne += boardOne[i][j];
				toInsertTwo += boardTwo[i][j];
				visitedOne[i][j] = visitedTwo[i][j] = true;
				GetCombination(i, j);
				visitedOne[i][j] = visitedTwo[i][j] = false;
			}
		if (first.empty() || second.empty()) {
			puts("There are no common words for this pair of boggle boards.");
		} else {
			if (size(first) < size(second)) {
				for (set<string>::iterator t = first.begin(); t != first.end(); t++) {
					it = second.find(*t);
					if (it != second.end())
						toPrint.push_back(*t);
				}
			} else {
				for (set<string>::iterator t = second.begin(); t != second.end(); t++) {
					it = first.find(*t);
					if (it != first.end())
						toPrint.push_back(*t);
				}
			}
			if (toPrint.empty())
				puts("There are no common words for this pair of boggle boards.");
			else for (int i = 0; i < size(toPrint); i++)
				cout << toPrint[i] << endl;
		}
		flag = true;
		toPrint.clear();
		first.clear();
		second.clear();
	}
	return 0;
}