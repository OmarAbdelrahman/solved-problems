#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
using namespace std;

#define MAX 101

int w, h, total, res;
bool vis[MAX * 5][MAX * 5];

int main() {
	while (cin >> w >> h >> total && (w || h || total)) {
		res = 0;
		memset(vis, false, sizeof vis);
		for (int i = 0; i < total; ++i) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (int r = min(x1, x2); r <= max(x1, x2); ++r)
				for (int c = min(y1, y2); c <= max(y1, y2); ++c)
					vis[r][c] = true;
		}
		for (int i = 1; i <= w; ++i)
			for (int j = 1; j <= h; ++j)
				if (!vis[i][j]) ++res;
		if (res == 0) {
			cout << "There is no empty spots." << endl;
		} else if (res == 1) {
			cout << "There is one empty spot." << endl;
		} else {
			cout << "There are " << res << " empty spots." << endl;
		}
	}
	return 0;
}