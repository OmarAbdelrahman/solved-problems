#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
  }
};

const int DLEN = 10;
const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

inline bool ok(const string& s) {
  if (s[2] != '-' || s[5] != '-') {
    return false;
  }
  char ch;
  int day, month, year;
  stringstream sin(s);
  sin >> day >> ch >> month >> ch >> year;
  return day > 0 && month > 0 && day <= daysInMonth[month] && year >= 2013 && year <= 2015;
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  map<string, int> counter;
  int m_count = 0;
  string s = io::next<string>();
  for (int i = 0; i + DLEN <= s.length(); ++i) {
    string sub = s.substr(i, DLEN);
    if (count(sub.begin(), sub.end(), '-') != 2) {
      continue;
    }
    if (ok(sub)) {
      ++counter[sub];
      m_count = max(m_count, counter[sub]);
    }
  }
  for (auto& p : counter) {
    if (p.second == m_count) {
      cout << p.first << endl;
      break;
    }
  }
  return 0;
}