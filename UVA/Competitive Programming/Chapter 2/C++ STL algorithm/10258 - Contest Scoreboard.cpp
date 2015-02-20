#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

#define SIZE(a) ((int)a.size())

struct Team {
	int id, solved, penalty;
	int problem_penalty[10];
	bool accepted[10];
	Team() {
		this->solved = this->penalty = 0;
		memset(problem_penalty, 0, sizeof(problem_penalty));
		memset(accepted, false, sizeof(accepted));
	}
	Team(int id, int solved, int penalty) {
		Team();
		this->id = id;
		this->solved = solved;
		this->penalty = penalty;
	}
	bool operator < (const Team& t) const {
		if (this->solved != t.solved)
			return this->solved > t.solved;
		else if (this->penalty != t.penalty)
			return this->penalty < t.penalty;
		else
			return this->id < t.id;
	}
};

int main() {
	int kases; cin >> kases;
	cin.ignore();
	string s; getline(cin, s);
	for (bool first = true; kases--; first = false) {
		if (!first) cout << endl;
		vector<Team> score_board;
		for (string str; getline(cin, str) && !str.empty();) {
			stringstream sin(str);
			char response;
			int id, problem, penalty;
			sin >> id >> problem >> penalty >> response;
			bool found = false;
			for (int i = 0; i < SIZE(score_board); ++i)
				if (id == score_board[i].id) {
					found = true;
					if (score_board[i].accepted[problem]) continue;
					if (response == 'C') {
						score_board[i].solved++;
						score_board[i].penalty += (score_board[i].problem_penalty[problem] + penalty);
						score_board[i].accepted[problem] = true;
					}
					if (response == 'I') {
						score_board[i].problem_penalty[problem] += 20;
					}
				}
			if (!found) {
				score_board.push_back(Team());
				int index = SIZE(score_board) - 1;
				score_board[index].id = id;
				if (response == 'C') {
					score_board[index].solved++;
					score_board[index].penalty += (score_board[index].problem_penalty[problem] + penalty);
					score_board[index].accepted[problem] = true;
				}
				if (response == 'I') {
					score_board[index].problem_penalty[problem] += 20;
				}
			}
		}
		sort(score_board.begin(), score_board.end());
		for (int i = 0; i < SIZE(score_board); ++i)
			cout << score_board[i].id << " " << score_board[i].solved << " " << score_board[i].penalty << endl;
	}
	return 0;
}
