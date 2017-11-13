#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define MAX 55

string cards[] = {
	"C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CT", "CJ", "CQ", "CK", "CA",
	"D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DT", "DJ", "DQ", "DK", "DA",
	"H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HT", "HJ", "HQ", "HK", "HA",
	"S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "ST", "SJ", "SQ", "SK", "SA"
};
string c[] = {
	"C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CT", "CJ", "CQ", "CK", "CA",
	"D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DT", "DJ", "DQ", "DK", "DA",
	"H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HT", "HJ", "HQ", "HK", "HA",
	"S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "ST", "SJ", "SQ", "SK", "SA"
};
int decksNum;
int decks[MAX * 2][MAX];

void print() {
	for (int i = 0; i < 52; ++i) {
		char rank = cards[i][1];
		char suit = cards[i][0];
		switch (rank) {
			case 'T':
				printf("10 ");
				break;
			case 'J':
				printf("Jack ");
				break;
			case 'Q':
				printf("Queen ");
				break;
			case 'K':
				printf("King ");
				break;
			case 'A':
				printf("Ace ");
				break;
			default:
				printf("%c ", rank);
				break;
		}
		printf("of ");
		switch (suit) {
			case 'C': printf("Clubs"); break;
			case 'D': printf("Diamonds"); break;
			case 'S': printf("Spades"); break;
			case 'H': printf("Hearts"); break;
		}
		printf("\n");
	}
}

int main() {
	int n;
	string s;
	getline(cin, s);
	sscanf(s.c_str(), "%d", &n);
	getline(cin, s);
	bool first = true;
	while (n--) {
		if (!first) cout << endl;
		first = false;
		cin >> decksNum;
		for (int i = 0; i < decksNum; ++i)
			for (int j = 0; j < 52; ++j) {
				scanf("%d", &decks[i][j]);
				--decks[i][j];
			}
		cin.ignore();
		string kShuffle;
		while (getline(cin, kShuffle)) {
			if (kShuffle.empty()) break;
			int indx;
			sscanf(kShuffle.c_str(), "%d", &indx);
			--indx;
			string cur[52];
			for (int i = 0; i < 52; ++i) {
				cur[i] = cards[decks[indx][i]];
			}
			for (int i = 0; i < 52; ++i)
				cards[i] = cur[i];
		}
		print();
		for (int i = 0; i < 52; ++i)
			cards[i] = c[i];
	}
	return 0;
}
