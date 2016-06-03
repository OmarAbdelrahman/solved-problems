#include <bits/stdc++.h>
using namespace std;

int d(const char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return c - 'A' + 10;
}

int to_decimal(string s, const int base) {
  int result = 0;
  int power = 1;
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); ++i) {
    const int x = d(s[i]);
    result += (x * power);
    power *= base;
  }
  return result;
}

bool ok(const int h, const int m) {
  return h < 24 && m < 60;
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  string s; cin >> s;
  const int p = s.find(':');
  int start_base = 1;

  string a = s.substr(0, p);
  string b = s.substr(p + 1, s.size() - p);

  if (ok(to_decimal(a, 60), to_decimal(b, 60))) {
    cout << -1 << endl;
    return 0;
  }

  const string hm = a + b;
  for (auto c : hm) {
    start_base = max(start_base, d(c));
  }

  vector<int> result;
  for (int base = start_base + 1; base < 60; ++base) {
    const int h = to_decimal(a, base);
    const int m = to_decimal(b, base);
    if (ok(h, m)) {
      result.push_back(base);
    }
  }

  if (result.empty()) {
    cout << 0 << endl;
  } else {
    for (auto base : result) {
      cout << base << " ";
    }
    cout << endl;
  }
  return 0;
}
