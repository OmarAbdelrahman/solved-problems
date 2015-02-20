#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define MAX 8
char Board[MAX][MAX];
const string Black = "black";
const string White = "white";

void Input();
bool CheckBoard();
bool FindBlackKing();
bool FindWhiteKing();
bool IsAvailable(int, int);
bool CheckBlackKing(int, int);
bool CheckWhiteKing(int, int);
bool KnightCheck(int, int, char);
bool RookCheck(int, int, char, char);
bool BishopCheck(int, int, char, char);
bool PawnBlackCheck(int, int, char, char);
bool PawnWhiteCheck(int, int, char, char);

int main() {
	for (int gameNumber = 1;; gameNumber++) {
		Input();
		if (CheckBoard())
			break;
		if (FindBlackKing())
			printf("Game #%d: black king is in check.\n", gameNumber);
		else if (FindWhiteKing())
			printf("Game #%d: white king is in check.\n", gameNumber);
		else
			printf("Game #%d: no king is in check.\n", gameNumber);
	}
	return 0;
}

void Input() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> Board[i][j];
}

bool CheckBoard() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (Board[i][j] != '.')
				return false;
	return true;
}

bool FindBlackKing() {
	bool check = false;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (Board[i][j] == 'k')
				check = CheckBlackKing(i, j);
	return check;
}

bool FindWhiteKing() {
	bool check = false;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (Board[i][j] == 'K')
				check = CheckWhiteKing(i, j);
	return check;
}

bool IsAvailable(int i, int j) {
	return (i < MAX && j < MAX && i >= 0 && j >= 0);
}

bool CheckBlackKing(int i, int j) {
	if (KnightCheck(i, j, 'N'))
		return true;
	else if (BishopCheck(i, j, 'B', 'Q'))
		return true;
	else if (PawnBlackCheck(i, j, 'P', 'Q'))
		return true;
	else if (RookCheck(i, j, 'R', 'Q'))
		return true;
	else return false;
}

bool CheckWhiteKing(int i, int j) {
	if (KnightCheck(i, j, 'n'))
		return true;
	else if (BishopCheck(i, j, 'b', 'q'))
		return true;
	else if (PawnBlackCheck(i, j, 'p', 'q'))
		return true;
	else if (RookCheck(i, j, 'r', 'q'))
		return true;
	else return false;
}

bool KnightCheck(int i, int j, char toCheck) {
	int X = i;
	int Y = j;
	int arrX[] = {-2, -1, -2, -1, 1, 2, 1, 2};
	int arrY[] = {-1, -2, 1, 2, -2, -1, 2, 1};
	for (int k = 0; k < 8; k++) {
		int row = X + arrX[k];
		int col = Y + arrY[k];
		if (IsAvailable(row, col))
			if (Board[row][col] == toCheck)
				return true;
	}
	return false;
}

bool BishopCheck(int i, int j, char toCheck, char Queen) {
	for (int k = 1; k <= 7; k++) {
		if (IsAvailable(i + k, j + k)) {
			if (Board[i+k][j+k] != '.' && Board[i+k][j+k] != toCheck && Board[i+k][j+k] != Queen)
				break;
			if (Board[i+k][j+k] == toCheck || Board[i+k][j+k] == Queen)
				return true;
		}
	}
	for (int k = 1; k <= 7; k++) {
		if (IsAvailable(i + k, j - k)) {
			if (Board[i+k][j-k] != '.' && Board[i+k][j-k] != toCheck && Board[i+k][j-k] != Queen)
				break;
			if (Board[i+k][j-k] == toCheck || Board[i+k][j-k] == Queen)
				return true;
		}
	}
	for (int k = 1; k <= 7; k++) {
		if (IsAvailable(i - k, j - k)) {
			if (Board[i-k][j-k] != '.' && Board[i-k][j-k] != toCheck && Board[i-k][j-k] != Queen)
				break;
			if (Board[i-k][j-k] == toCheck || Board[i-k][j-k] == Queen)
				return true;
		}
	}
	for (int k = 1; k <= 7; k++) {
		if (IsAvailable(i - k, j + k)) {
			if (Board[i-k][j+k] != '.' && Board[i-k][j+k] != toCheck && Board[i-k][j+k] != Queen)
				break;
			if (Board[i-k][j+k] == toCheck || Board[i-k][j+k] == Queen)
				return true;
		}
	}
	return false;
}

bool PawnBlackCheck(int i, int j, char toCheck, char Queen) {
	if (IsAvailable(i + 1, j + 1)) {
		for (int k = 0; k < 1; k++)
			if (Board[i+1][j+1] == toCheck || Board[i+1][j+1] == Queen)
				return true;
	}
	if (IsAvailable(i + 1, j - 1)) {
		for (int k = 0; k < 1; k++)
			if (Board[i+1][j-1] == toCheck || Board[i+1][j-1] == Queen)
				return true;
	}
	return false;
}

bool PawnWhiteCheck(int i, int j, char toCheck, char Queen) {
	if (IsAvailable(i - 1, j - 1)) {
		for (int k = 0; k < 1; k++)
			if (Board[i-1][j-1] == toCheck || Board[i-1][j-1] == Queen)
				return true;
	}
	if (IsAvailable(i - 1, j + 1)) {
		for (int k = 0; k < 1; k++)
			if (Board[i-1][j+1] == toCheck || Board[i-1][j+1] == Queen)
				return true;
	}
	return false;
}

bool RookCheck(int i, int j, char toCheck, char Queen) {
	for (int k = 0; k <= 7; k++) {
		if (IsAvailable(i + k, j)) {
			if (Board[i+k][j] != '.' && Board[i+k][j] != toCheck && Board[i+k][j] != Queen)
				break;
			if (Board[i+k][j] == toCheck || Board[i+k][j] == Queen)
				return true;
		}
	}
	for (int k = 0; k <= 7; k++) {
		if (IsAvailable(i - k, j)) {
			if (Board[i-k][j] != '.' && Board[i-k][j] != toCheck && Board[i-k][j] != Queen)
				break;
			if (Board[i-k][j] == toCheck || Board[i-k][j] == Queen)
				return true;
		}
	}
	for (int k = 0; k <= 7; k++) {
		if (IsAvailable(i, j + k)) {
			if (Board[i][j+k] != '.' && Board[i][j+k] != toCheck && Board[i][j+k] != Queen)
				break;
			if (Board[i][j+k] == toCheck || Board[i][j+k] == Queen)
				return true;
		}
	}
	for (int k = 0; k <= 7; k++) {
		if (IsAvailable(i, j - k)) {
			if (Board[i][j-k] != '.' && Board[i][j-k] != toCheck && Board[i][j-k] != Queen)
				break;
			if (Board[i][j-k] == toCheck || Board[i][j-k] == Queen)
				return true;
		}
	}
	return false;
}