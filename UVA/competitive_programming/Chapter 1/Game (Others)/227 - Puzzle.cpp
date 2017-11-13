#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.size())

vector<string> puz;
string dir;
string in;
int cases = 1;

bool available(int x, int y) {
	return x >= 0 && y >= 0 && x < 5 && y < 5;
}

void getfinal(int i, int j) {
	bool check = false;
	for (int k = 0; k < SIZE(dir); ++k) {
		if (dir[k] == 'A') {
			if (!available(i - 1, j)) {
				check = true;
				break;
			}
			swap(puz[i][j], puz[i - 1][j]);
			i = i - 1;
		} else if (dir[k] == 'B') {
			if (!available(i + 1, j)) {
				check = true;
				break;
			}
			swap(puz[i][j], puz[i + 1][j]);
			i = i + 1;
		} else if (dir[k] == 'L') {
			if (!available(i, j - 1)) {
				check = true;
				break;
			}
			swap(puz[i][j], puz[i][j - 1]);
			j = j - 1;
		} else if (dir[k] == 'R') {
			if (!available(i, j + 1)) {
				check = true;
				break;
			}
			swap(puz[i][j], puz[i][j + 1]);
			j = j + 1;
		} else {
			check = true;
			break;
		}
	}
	printf("Puzzle #%d:\n", cases);
	if (check) {
		puts("This puzzle has no final configuration.");
	} else {
		for (int r = 0; r < SIZE(puz); ++r) {
			for (int c = 0; c < LENGTH(puz[r]); ++c) {
				if (c == LENGTH(puz[r]) - 1)
					cout << puz[r][c];
				else
					cout << puz[r][c] << ' ';
			}
			cout << endl;
		}
	}
}

int main() {
	int cn = 0;
	bool flag = false;
	while (getline(cin, in) && in != "Z") {
		puz.push_back(in);
		cn++;
		if (cn == 5) {
			if (flag) cout << endl;
			char ch;
			while (cin >> ch && ch != '0')
				dir += ch;
			int x, y;
			bool check = 0;
			for (int i = 0; i < SIZE(puz); ++i) {
				for (int j = 0; j < LENGTH(puz[i]); ++j)
					if (puz[i][j] == ' ') {
						x = i, y = j;
						check = true;
					}
				if (check) break;
			}
			getfinal(x, y);
			cn = 0;
			puz.clear();
			dir = "";
			cin.ignore();
			cases++;
			flag = true;
		}
	}
	return 0;
}
