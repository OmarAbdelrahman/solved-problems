#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
	int m_numberOfSets;
	vector<int> numberOfBricks;
	for (int setNumber = 0; cin >> m_numberOfSets && m_numberOfSets != 0; setNumber++) {
		int totalBricks = 0;
		numberOfBricks.resize(m_numberOfSets);
		for (int i = 0; i < m_numberOfSets; i++) {
			cin >> numberOfBricks[i];
			totalBricks += numberOfBricks[i];
		}
		int minimumMoves = 0;
		int m_height = totalBricks / m_numberOfSets;
		for (int i = 0; i < m_numberOfSets; i++)
			if (numberOfBricks[i] > m_height)
				minimumMoves += (numberOfBricks[i] - m_height);
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", setNumber + 1, minimumMoves);
	}
	return 0;
}