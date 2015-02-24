#include <bits/stdc++.h>
using namespace std;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
  }

  template<class T, typename Fun>
  static inline T next(Fun f) {
    T x; std::cin >> x;
    return f(x);
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  const string s = io::next<string>();
  const string t = io::next<string>();

  const int n = s.length();
  const int m = t.length();

  bool automaton = false;
  for (int i = 0, j = 0; i < n && !automaton; ++i) {
    if (j < m && s[i] == t[j]) ++j;
    if (j == m) automaton = true;
  }

  unordered_map<char, int> freq;
  for (char ch : s) freq[ch]++;
  for (char ch : t) freq[ch]--;

  bool anagram = true;
  bool both = true;
  for (auto p : freq) {
    anagram &= p.second == 0;
    both &= p.second >= 0;
  }

  if (automaton)
    cout << "automaton" << endl;
  else if (anagram)
    cout << "array" << endl;
  else if (both)
    cout << "both" << endl;
  else
    cout << "need tree" << endl;
  return 0;
}
