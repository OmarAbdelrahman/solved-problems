/*
ID: 1010
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <string.h>
using namespace std;

#define sz(a) ((int)a.size())
#define max_t 200000 + 10

struct node_t {
	node_t() {
		this->flag = false;
		for (int i = 0; i < 26; ++i) 
			this->next[i] = NULL;
	}
	~node_t() {
		for (int i = 0; i < 26; ++i) 
			if (this->next[i]) delete this->next[i];
	}
	bool flag;
	node_t* next[26];
};

node_t tree;
set<string> prim;
char seq[max_t];
bool ok[max_t];

void insert(string& str) {
	node_t* ptr = &tree;
	for (int i = 0; i < sz(str); ++i) {
		if (ptr->next[str[i] - 'A'] == NULL)
			ptr->next[str[i] - 'A'] = new node_t;
		ptr = ptr->next[str[i]-'A'];
	}
	ptr->flag = true;
}

bool cnt(char* st, char* en) {
	char* ch = st;
	node_t* ptr = &tree;
	for (; ch != en; ++ch) {
		if (ptr->next[*ch - 'A'] == NULL)
			return false;
		ptr = ptr->next[*ch - 'A'];
	}
	return ptr->flag;
}

template<class T> inline void get_max(T& a, T b) {
	if (a < b) a = b;
}

int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	int len = 0;
	for (string s; cin >> s && s != "."; insert(s));
	for (string s; cin >> s;) 
		for (int i = 0; i < sz(s); ++i) 
			seq[len++] = s[i];
	seq[len] = '\0';
	ok[0] = true;
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		if (!ok[i]) continue;
		for (int j = 1; j <= 10; ++j)
			if (cnt(seq + i, seq + i + j)) {
				ok[i + j] = true;
				get_max(ans, i + j);
			}
	}
	cout << ans << endl;
	return 0;
}