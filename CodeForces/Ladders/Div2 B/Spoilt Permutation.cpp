#include <bits/stdc++.h>
using namespace std;

struct input_data {
  vector<int> a;
};

struct output_data {
  int l, r;
};

istream& operator >> (istream& istr, input_data& input) {
  int n; istr >> n;
  input.a.resize(n);
  for (int i = 0; i < n; i++) {
    istr >> input.a[i];
    input.a[i]--;
  }
  return istr;
}

ostream& operator << (ostream& ostr, const output_data& output) {
  ostr << output.l << " " << output.r;
  return ostr;
}

output_data solve(input_data input) {
  const int n = input.a.size();
  vector<int> a = input.a;
  output_data result = { 0, 0 };
  for (int i = 0; i < n; i++) {
    if (a[i] == i) continue;
    if (a[a[i]] == i && result.r == 0) {
      int j = i + 1;
      while (j < n && a[j - 1] == a[j] + 1 && a[a[j]] == j) {
        ++j;
      }
      result = { i + 1, j };
      i = j - 1;
    } else {
      return { 0, 0 };
    }
  }
  return result;
}

int main() {
  input_data input; cin >> input;
  cout << solve(input) << endl;
  return 0;
}