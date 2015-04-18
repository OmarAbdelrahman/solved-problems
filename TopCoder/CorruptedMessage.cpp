#include <bits/stdc++.h>
using namespace std;

class CorruptedMessage {
public:
	string reconstructMessage(string s, int k) {
		const int n = s.length();

		unordered_map<char, int> freq;
		for (char ch : s) freq[ch]++;

		for (char ch = 'a'; ch <= 'z'; ++ch) {
			if (n - freq[ch] == k) {
				return string(n, ch);
			}
		}
		return "";
	}
};