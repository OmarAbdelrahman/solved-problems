#include <cstring>
#include <cstdio>

using namespace std;

inline bool isVowel(char& ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int nCases;
	scanf("%d", &nCases);
	char name[25], mutat[25];
	while (nCases--) {
		scanf("%s%s", name, mutat);
		int nameLength = int(strlen(name));
		int mutatLength = int(strlen(mutat));
		if (nameLength != mutatLength) {
			puts("No"); 
			continue;
		}
		bool ok = true;
		for (int index = 0; index < nameLength; ++index) {
			if (name[index] != mutat[index]) {
				if (isVowel(name[index]) && !isVowel(mutat[index])) {
					ok = false;
					break;
				} else if (!isVowel(name[index])) {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}
