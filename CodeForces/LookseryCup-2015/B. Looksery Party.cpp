#include <bits/stdc++.h>
using namespace std;

string g[110];
int expected[110];
int msg_count[110];
int answer[110];

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> expected[i];
  }
  for (int i = 0; i < n; ++i) {
    answer[i] = i + 1;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (g[i][j] == '1') {
        ++msg_count[j];
      }
    }
  }

  int size = n;
  while (true) {
    bool one = false;
    for (int i = 0; i < n && !one; ++i) {
      if (msg_count[i] == expected[i]) {
        one = true;
        --size;
        answer[i] = -1;
        for (int j = 0; j < n; ++j) {
          if (g[i][j] == '1') {
            --msg_count[j];
          }
        }
      }
    }
    if (!one) {
      break;
    }
  }

  cout << size << endl;
  for (int i = 0; i < n; ++i) {
    if (answer[i] != -1) {
      cout << answer[i] << " ";
    }
  }
  cout << endl;
  return 0;
}