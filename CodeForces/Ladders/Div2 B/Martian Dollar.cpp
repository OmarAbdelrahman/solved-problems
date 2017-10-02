#include <bits/stdc++.h>
using namespace std;

struct input_data {
  int b;
  vector<int> a;
};

struct output_data {
  int n;
};

istream& operator >> (istream& istr, input_data& input) {
  int n;
  istr >> n >> input.b;
  input.a.resize(n);
  for (int& i : input.a) {
    istr >> i;
  }
  return istr;
}

ostream& operator << (ostream& ostr, const output_data& output) {
  ostr << output.n;
  return ostr;
}

output_data solve(input_data input) {
  const int n = input.a.size();
  const int bouries = input.b;
  const vector<int> a = input.a;
  int result = bouries;
  for (int i = 0; i < n; i++) {
    const int ds = bouries / a[i];
    for (int j = i + 1; j < n; j++) {
      const int rem = bouries - ds * a[i];
      result = max(result, rem + ds * a[j]);
    }
  }
  return { result };
}

int main(int argc, char** argv) {
  input_data input;
  cin >> input;
  cout << solve(input) << endl;
  return 0;
}