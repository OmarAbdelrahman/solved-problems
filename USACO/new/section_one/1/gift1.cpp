/*
ID: omar.se1
LANG: C++11
TASK: gift1
 */

#include <bits/stdc++.h>
using namespace std;

string names[20];
int net_value[20];

int main() {
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }
  string giver;
  string taker;
  int amount, count;
  for (int i = 0; i < n; i++) {
    cin >> giver;
    scanf("%d%d", &amount, &count);
    if (count == 0) {
      continue;
    }
    int to_give = amount / count;
    int to_keep = amount % count;
    for (int j = 0; j < count; j++) {
      cin >> taker;
      for (int k = 0; k < n; k++) {
        if (names[k] == taker) {
          net_value[k] += to_give;
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (names[j] == giver) {
        net_value[j] -= amount;
        net_value[j] += to_keep;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%s %d\n", names[i].c_str(), net_value[i]);
  }
  return 0;
}
