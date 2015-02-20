#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())
#define ALL(c) c.begin(), c.end()

string dir;

int suitVal(char& ch) {
	if (ch == 'C') return 0;
	if (ch == 'D') return 1;
	if (ch == 'S') return 2;
	if (ch == 'H') return 3;
	return 4;
}

char suitChar(int& n) {
	if (n == 0) return 'C';
	if (n == 1) return 'D';
	if (n == 2) return 'S';
	if (n == 3) return 'H';
	return '-';
}

int rankVal(char& ch) {
	if (isdigit(ch)) return ch - '0';
	if (ch == 'T') return 10;
	if (ch == 'J') return 11;
	if (ch == 'Q') return 12;
	if (ch == 'K') return 13;
	if (ch == 'A') return 14;
	return 15;
}

char rankChar(int& n) {
	if (n >= 2 && n <= 9) return n + '0';
	if (n == 10) return 'T';
	if (n == 11) return 'J';
	if (n == 12) return 'Q';
	if (n == 13) return 'K';
	if (n == 14) return 'A';
	return '-';
}

int getIndex(char& ch) {
	if (ch == 'N') return 0;
	if (ch == 'E') return 1;
	if (ch == 'S') return 2;
	if (ch == 'W') return 3;
	return 4;
}

int main() {
	dir = "NESW";
	int n = LENGTH(dir);
	for (char ch; cin >> ch && ch != '#';) {
		string s1; cin >> s1;
		string s2; cin >> s2;
		vector<pair<int, int> > N, E, S, W;
		int indx = getIndex(ch);
		indx = (indx + 1) % n;
		for (int i = 0; i < LENGTH(s1); i += 2) {
			pair<int, int> card(suitVal(s1[i]), rankVal(s1[i + 1]));
			switch (dir[indx]) {
				case 'N': N.push_back(card); break;
				case 'E': E.push_back(card); break;
				case 'S': S.push_back(card); break;
				case 'W': W.push_back(card); break;
			}
			indx = (indx + 1) % n;
		}
		for (int i = 0; i < LENGTH(s2); i += 2) {
			pair<int, int> card(suitVal(s2[i]), rankVal(s2[i + 1]));
			switch (dir[indx]) {
				case 'N': N.push_back(card); break;
				case 'E': E.push_back(card); break;
				case 'S': S.push_back(card); break;
				case 'W': W.push_back(card); break;
			}
			indx = (indx + 1) % n;
		}
		sort(ALL(N)); sort(ALL(E)); sort(ALL(S)); sort(ALL(W));
		printf("S:");
		for (int i = 0; i < SIZE(S); ++i)
			printf(" %c%c", suitChar(S[i].first), rankChar(S[i].second));
		printf("\n");
		printf("W:");
		for (int i = 0; i < SIZE(W); ++i)
			printf(" %c%c", suitChar(W[i].first), rankChar(W[i].second));
		printf("\n");
		printf("N:");
		for (int i = 0; i < SIZE(N); ++i)
			printf(" %c%c", suitChar(N[i].first), rankChar(N[i].second));
		printf("\n");
		printf("E:");
		for (int i = 0; i < SIZE(E); ++i)
			printf(" %c%c", suitChar(E[i].first), rankChar(E[i].second));
		printf("\n");
	}
	return 0;
}
