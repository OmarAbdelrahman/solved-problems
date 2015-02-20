#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include <sstream>
using namespace std;

struct Suit {
	int numCards;
	int K, Q, J;
	bool stopped;
	Suit() {
		numCards = K = Q = J = 0;
		stopped = false;
	}
};

int val(char& ch) {
	if (ch == 'A') return 4;
	if (ch == 'K') return 3;
	if (ch == 'Q') return 2;
	if (ch == 'J') return 1;
	return 0;
}

map<char, int> suitFreq;
vector<string> hand;
string suit;

int main() {
	suit = "SHDC";
	for (string s; getline(cin, s);) {
		stringstream sin(s);
		for (string ss; sin >> ss; hand.push_back(ss));
		Suit S, H, D, C;
		int handVal = 0;
		for (int i = 0; i < (int)hand.size(); ++i) {
			string now = hand[i];
			char curVal = now[0];
			char curSuit = now[1];
			++suitFreq[curSuit];
			switch (curSuit) {
				case 'S':
					if (curVal == 'K') ++S.K;
					else if (curVal == 'Q') ++S.Q;
					else if (curVal == 'J') ++S.J;
					else {
						if (curVal == 'A')
							S.stopped = true;
						++S.numCards;
					}
					break;
				case 'H':
					if (curVal == 'K') ++H.K;
					else if (curVal == 'Q') ++H.Q;
					else if (curVal == 'J') ++H.J;
					else {
						if (curVal == 'A')
							H.stopped = true;
						++H.numCards;
					}
					break;
				case 'D':
					if (curVal == 'K') ++D.K;
					else if (curVal == 'Q') ++D.Q;
					else if (curVal == 'J') ++D.J;
					else {
						if (curVal == 'A')
							D.stopped = true;
						++D.numCards;
					}
					break;
				case 'C':
					if (curVal == 'K') ++C.K;
					else if (curVal == 'Q') ++C.Q;
					else if (curVal == 'J') ++C.J;
					else {
						if (curVal == 'A')
							C.stopped = true;
						++C.numCards;
					}
					break;
			}
			handVal += val(curVal);
		}
		if (S.K && S.Q + S.J + S.numCards >= 1) S.stopped = true;
		if (S.Q && S.K + S.J + S.numCards >= 2) S.stopped = true;
		if (H.K && H.Q + H.J + H.numCards >= 1) H.stopped = true;
		if (H.Q && H.K + H.J + H.numCards >= 2) H.stopped = true;
		if (D.K && D.Q + D.J + D.numCards >= 1) D.stopped = true;
		if (D.Q && D.K + D.J + D.numCards >= 2) D.stopped = true;
		if (C.K && C.Q + C.J + C.numCards >= 1) C.stopped = true;
		if (C.Q && C.K + C.J + C.numCards >= 2) C.stopped = true;
		if (S.K && S.Q + S.J + S.numCards == 0) --handVal;
		if (S.Q && (S.K + S.J + S.numCards == 0 || S.K + S.J + S.numCards == 1)) --handVal;
		if (S.J && (S.K + S.Q + S.numCards == 0 || S.K + S.Q + S.numCards == 1 || S.K + S.Q + S.numCards == 2)) --handVal;
		if (H.K && H.Q + H.J + H.numCards == 0) --handVal;
		if (H.Q && (H.K + H.J + H.numCards == 0 || H.K + H.J + H.numCards == 1)) --handVal;
		if (H.J && (H.K + H.Q + H.numCards == 0 || H.K + H.Q + H.numCards == 1 || H.K + H.Q + H.numCards == 2)) --handVal;
		if (D.K && D.Q + D.J + D.numCards == 0) --handVal;
		if (D.Q && (D.K + D.J + D.numCards == 0 || D.K + D.J + D.numCards == 1)) --handVal;
		if (D.J && (D.K + D.Q + D.numCards == 0 || D.K + D.Q + D.numCards == 1 || D.K + D.Q + D.numCards == 2)) --handVal;
		if (C.K && C.Q + C.J + C.numCards == 0) --handVal;
		if (C.Q && (C.K + C.J + C.numCards == 0 || C.K + C.J + C.numCards == 1)) --handVal;
		if (C.J && (C.K + C.Q + C.numCards == 0 || C.K + C.Q + C.numCards == 1 || C.K + C.Q + C.numCards == 2)) --handVal;
		bool noTrump = false;
		if (handVal >= 16) {
			if (S.stopped && H.stopped && D.stopped && C.stopped) {
				printf("BID NO-TRUMP\n");
				noTrump = true;
			}
		}
		if (noTrump) {
			hand.clear();
			suitFreq.clear();
			continue;
		}
		for (int i = 0; i < (int)suit.length(); ++i) {
			int freq = suitFreq[suit[i]];
			if (freq == 2)
				++handVal;
			else if (freq == 1 || freq == 0)
				handVal += 2;
		}
		if (handVal < 14) {
			printf("PASS\n");
		} else if (handVal >= 14) {
			int s = S.K + S.Q + S.J + S.numCards;
			int h = H.K + H.Q + H.J + H.numCards;
			int d = D.K + D.Q + D.J + D.numCards;
			int c = C.K + C.Q + C.J + C.numCards;
			if (s >= h && s >= d && s >= c) {
				printf("BID S\n");
			} else if (h >= s && h >= d && h >= c) {
				printf("BID H\n");
			} else if (d >= s && d >= h && d >= c) {
				printf("BID D\n");
			} else if (c >= s && c >= h && c >= d) {
				printf("BID C\n");
			}
		}
		hand.clear();
		suitFreq.clear();
	}
	return 0;
}
