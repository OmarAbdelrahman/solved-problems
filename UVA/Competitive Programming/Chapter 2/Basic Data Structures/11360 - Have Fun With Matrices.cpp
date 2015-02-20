#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int matrix[10][10];
int sizeofMatrix;

bool IsTen(int);
bool IsNegative(int);
void Transpose();
void Increment();
void Decrement();
void ChangeRow(int, int);
void ChangeCol(int, int);

int main() {
	char temp;
	int numberofCases;
	int numberofOrders;
	string orders;
	scanf("%d", &numberofCases);
	for (int _Cases = 1; _Cases <= numberofCases; _Cases++) {
		scanf("%d", &sizeofMatrix);
		for (int i = 0; i < sizeofMatrix; i++)
			for (int j = 0; j < sizeofMatrix; j++) {
				cin >> temp;
				matrix[i][j] = temp - '0';
			}
		scanf("%d", &numberofOrders);
		for (int i = 0; i < numberofOrders; i++) {
			cin >> orders;
			if (orders == "transpose") {
				Transpose();
			} else if (orders == "inc") {
				Increment();
			} else if (orders == "dec") {
				Decrement();
			} else if (orders == "row") {
				int r, c;
				cin >> r >> c;
				ChangeRow(r, c);
			} else if (orders == "col") {
				int r, c;
				cin >> r >> c;
				ChangeCol(r, c);
			}
		}
		printf("Case #%d\n", _Cases);
		for (int i = 0; i < sizeofMatrix; i++) {
			for (int j = 0; j < sizeofMatrix; j++)
				cout << matrix[i][j];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

bool IsTen(int n) {
	return (n == 10);
}

bool IsNegative(int n) {
	return (n < 0);
}

void Transpose() {
	for (int i = 0; i < sizeofMatrix; i++)
		for (int j = 0; j < sizeofMatrix; j++)
			if (i != j) swap(matrix[i][j], matrix[j][i]);
}

void Increment() {
	for (int i = 0; i < sizeofMatrix; i++)
		for (int j = 0; j < sizeofMatrix; j++)
			if (IsTen(++matrix[i][j])) matrix[i][j] = 0;
}

void Decrement() {
	for (int i = 0; i < sizeofMatrix; i++)
		for (int j = 0; j < sizeofMatrix; j++)
			if (IsNegative(--matrix[i][j])) matrix[i][j] = 9;
}

void ChangeRow(int r1, int r2) {
	for (int i = 0; i < sizeofMatrix; i++)
		swap(matrix[r1 - 1][i], matrix[r2 - 1][i]);
}

void ChangeCol(int c1, int c2) {
	for (int i = 0; i < sizeofMatrix; i++)
		swap(matrix[i][c1 - 1], matrix[i][c2 - 1]);
}