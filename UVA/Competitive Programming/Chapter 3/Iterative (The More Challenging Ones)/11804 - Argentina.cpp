#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 11

struct player {
	string name;
	int att, def;
	player() {}
	player(string name, int att, int def) {
		this->name = name;
		this->att = att;
		this->def = def;
	}
	bool operator < (const player& p) const {
		return this->name < p.name;
	}
};

void print(string name[], int s, int e) {
	printf("(%s", name[s].c_str());
	for (int i = 1 + s; i < e; ++i)
		printf(", %s", name[i].c_str());
	printf(")\n");
}

int main() {
	int TC; scanf("%d", &TC);
	player data[MAX];
	bool vis[MAX];
	for (int a, b, c, d, e, i, kase = 1; TC--; ++kase) {
		for (a = 0; a < 10; ++a) {
			cin >> data[a].name >> data[a].att >> data[a].def;
			vis[a] = false;
		}
		sort(data, data + 10);
		int big_attack = -1;
		int big_defense = -1;
		string res[MAX], T[MAX];
		for (a = 0; a < 10; ++a)
			for (b = 0; b < 10; ++b) if (b != a)
				for (c = 0; c < 10; ++c) if (c != b && c != a)
					for (d = 0; d < 10; ++d) if (d != c && d != b && d != a)
						for (e = 0; e < 10; ++e)
							if (e != d && e != c && e != b && e != a) {
								vis[a] = vis[b] = vis[c] = vis[d] = vis[e] = true;
								int i1 = 0, i2 = 5;
								int att = 0, def = 0;
								for (i = 0; i < 10; ++i)
									if (vis[i]) {
										T[i1++] = data[i].name;
										att += data[i].att;
									} else {
										T[i2++] = data[i].name;
										def += data[i].def;
									}
								if (att > big_attack) {
									big_attack = att;
									big_defense = -1;
									for (i = 0; i < 10; ++i)
										res[i] = T[i];
								} else if (att == big_attack) {
									if (def > big_defense) {
										big_defense = def;
										for (i = 0; i < 10; ++i)
											res[i] = T[i];
									}
								}
								vis[a] = vis[b] = vis[c] = vis[d] = vis[e] = false;
							}
		printf("Case %d:\n", kase);
		print(res, 0, 5);
		print(res, 5, 10);
	}
	return 0;
}