/*
ID: 1010
PROG: ride
LANG: C++
*/
#include <iostream>
#include <string>
using namespace std;

#define SIZE(A) ((int)A.size())

int main() {
    freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);
    string name_ofComet;
	string name_ofGroup;
	while (cin >> name_ofComet >> name_ofGroup) {	
		int cometNumber = 1;
		int groupNumber = 1;
		for (int i = 0; i < 6; i++) {
			if (i < SIZE(name_ofComet))
				cometNumber *= (name_ofComet[i] - 'A') + 1;
			if (i < SIZE(name_ofGroup))
				groupNumber *= (name_ofGroup[i] - 'A') + 1;
		}
		if ((cometNumber % 47) == (groupNumber % 47))
			cout << "GO" << endl;
		else
			cout << "STAY" << endl;
		name_ofComet.clear();
		name_ofGroup.clear();
	}
    return 0;
}