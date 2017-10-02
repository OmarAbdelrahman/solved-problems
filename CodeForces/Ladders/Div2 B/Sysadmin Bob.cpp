#include <bits/stdc++.h>
using namespace std;

inline void no_solution() {
  puts("No solution");
  exit(0);
}

int main(int argc, char** argv) {
  string s;
  cin >> s;
  int pos = -1;
  int n = (int) s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != '@') {
      continue;
    }
    if (pos == -1) {
      if (i == 0 || i == n - 1) {
        no_solution();
      }
    } else {
      if (i - pos <= 2 || i == n - 1) {
        no_solution();
      }
    }
    pos = i;
  }
  if (pos == -1) {
    no_solution();
  }
  for (int i = 0; i < n; i++) {
    cout << s[i];
    if (s[i] == '@' && i != pos) {
      cout << s[++i] << ",";
    }
  }
  cout << endl;
  return 0;
}