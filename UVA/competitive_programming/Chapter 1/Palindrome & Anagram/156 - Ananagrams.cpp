#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define SZ(a) ((int)a.size())
#define REP(i, e) for (int i = 0; i < e; ++i)
#define FOREACH(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(c) c.begin(), c.end()

int main() {
	vector<string> words;
	for (string s; cin >> s && s != "#"; words.push_back(s));
	set<string> res;
	REP(i, SZ(words)) {
		string now = words[i];
		REP(j, SZ(now)) now[j] = tolower(now[j]);
		sort(ALL(now));
		bool ok = true;
		REP(j, SZ(words)) if (i != j) {
			string search = words[j];
			REP(k, SZ(search)) search[k] = tolower(search[k]);
			sort(ALL(search));
			if (now == search) {ok = false; break;}
		}
		if (ok) res.insert(words[i]);
	}
	FOREACH(word, res) cout << *word << endl;
	return 0;
}