#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int a[100010][3];

bool inside(int x, int a, int b) {
  return a <= x && x <= b;
}

void move_f(int& s, int l, int r, int n, string& result) {
  if (s + 1 <= n && !inside(s + 1, l, r)) {
    result += "R";
    ++s;
  } else {
    result += "X";
  }
}

void move_b(int& s, int l, int r, int n, string& result) {
  if (s - 1 >= 1 && !inside(s - 1, l, r)) {
    result += "L";
    --s;
  } else {
    result += "X";
  }
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, m, s, f; cin >> n >> m >> s >> f;
  for (int i = 0; i < m; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  string result = "";
  int cur_t = 1;
  for (int i = 0; i < m && s != f; ++i) {
    int t = a[i][0];
    int l = a[i][1];
    int r = a[i][2];

    if (cur_t == t) {
      if (inside(s, l, r)) {
        result += "X";
      } else {
        if (s < f) {
          move_f(s, l, r, n, result);
        } else {
          move_b(s, l, r, n, result);
        }
      }
      ++cur_t;
    } else {
      int diff = t - cur_t + (i == 0 ? 0 : 1);
      int dist = s - f;
      int sz = min(abs(dist), diff);
      if (dist < 0) {
        result += string(sz, 'R');
        s += sz;
      } else {
        result += string(sz, 'L');
        s -= sz;
      }
      cur_t = t + (i == 0 ? 0 : 1);
      if (i == 0) {
        --i;
      }
    }
  }
  if (s != f) {
    if (s < f) {
      result += string(f - s, 'R');
    } else {
      result += string(s - f, 'L');
    }
  }
  cout << result << "\n";
  return 0;
}