#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

string to_string(int64 x) {
  stringstream sin; sin << x;
  return sin.str();
}

string solve(int64 a, int64 b) {
  if (b % 10 == 9) {
    return solve(a / 10, b / 10) + '9';
  }
  if (a / 10 < b / 10) {
    return solve(a / 10, b / 10 - 1) + '9';
  }
  return to_string(b);
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int64 p, d; cin >> p >> d;
  string result = solve(p - d, p);
  while (result[0] == '0') {
    result.erase(result.begin());
  }
  cout << result << "\n";
  return 0;
}