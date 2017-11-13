#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int test_cases; scanf("%d", &test_cases);
	while (test_cases--) {
		int players, transfers, rolls;
		scanf("%d%d%d", &players, &transfers, &rolls);
		int* player = new int[players];
		pair<int, int>* positions = new pair<int, int>[transfers];
		for (int i = 0; i < transfers; ++i)
			scanf("%d%d", &positions[i].first, &positions[i].second);
		fill(player, player + players, 1);
		int die_value;
		for (int i = 0, j = 0; i < rolls; ++i, j = (j + 1) % players) {
			scanf("%d", &die_value);
			if (player[j] + die_value >= 100) {
				player[j] = 100;
				for (int k = i + 1; k < rolls; ++k) scanf("%d", &die_value);
				break;
			} else
				player[j] += die_value;
			for (int k = 0; k < transfers; ++k)
				if (player[j] == positions[k].first) {
					player[j] = positions[k].second;
					break;
				}
			if (player[j] == 100) {
				for (int k = i + 1; k < rolls; ++k) scanf("%d", &die_value);
				break;
			}
		}
		for (int i = 0; i < players; ++i)
			printf("Position of player %d is %d.\n", i + 1, player[i]);
		delete player;
		delete positions;
	}
	return 0;
}