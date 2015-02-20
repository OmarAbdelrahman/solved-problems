#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
using namespace std;

#define SIZE(a) ((int)a.size())
#define LENGTH(a) ((int)a.length())

struct frame {
	int r1, r2;
	bool strike;
	bool spare;
	frame() {
		this->r1 = 0;
		this->r2 = 0;
		this->strike = false;
		this->spare = false;
	}
};

int get(int i, vector<frame>& f) {
	if (!f[i].spare && !f[i].strike)
		return f[i].r1 + f[i].r2;
	if (f[i].spare)
		return 10 + f[i + 1].r1;
	int res = 10 + f[i + 1].r1;
	if (f[i + 1].strike)
		res += f[i + 2].r1;
	else
		res += f[i + 1].r2;
	return res;
}

int main() {
	for (string input; getline(cin, input);) {
		if (input == "Game Over") break;
		for (int i = 0; i < LENGTH(input); ++i)
			if (input[i] == ' ') input.erase(i--, 1);
		int n = LENGTH(input);
		vector<frame> game_frame(15, frame());
		for (int i = 0, j = 0; i < n; ++i, ++j) {
			if (input[i] == 'X') {
				game_frame[j].r1 = 10;
				game_frame[j].strike = true;
			} else {
				game_frame[j].r1 = input[i] - '0';
				if (input[i + 1] == '/') {
					game_frame[j].r2 = 10 - game_frame[j].r1;
					game_frame[j].spare = true;
				} else {
					game_frame[j].r2 = input[i + 1] - '0';
				}
				++i;
			}
		}
		int res = 0;
		for (int i = 0; i < 10; ++i)
			res += get(i, game_frame);
		printf("%d\n", res);
	}
	return 0;
}