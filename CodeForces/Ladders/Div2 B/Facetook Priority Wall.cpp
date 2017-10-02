#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
  string me;
  cin >> me;
  int n;
  cin >> n;
  unordered_map<string, int> score;
  for (int i = 0; i < n; i++) {
    string n1, n2;
    string action;
    cin >> n1 >> action;
    int value = 0;
    if (action == "posted") {
      cin >> n2 >> n2;
      n2 = n2.substr(0, (int) n2.length() - 2);
      value = 15;
    } else if (action == "commented") {
      cin >> n2 >> n2;
      n2 = n2.substr(0, (int) n2.length() - 2);
      value = 10;
    } else {
      cin >> n2;
      n2 = n2.substr(0, (int) n2.length() - 2);
      value = 5;
    }
    if (!score.count(n1)) {
      score[n1] = 0;
    }
    if (!score.count(n2)) {
      score[n2] = 0;
    }
    if (n1 == me || n2 == me) {
      score[n1] += value;
      score[n2] += value;
    }
    cin >> action;
  }
  vector<pair<string, int>> people(score.begin(), score.end());
  sort(people.begin(), people.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });
  for (const auto p : people) {
    if (p.first != me) {
      cout << p.first << endl;
    }
  }
  return 0;
}