#include <bits/stdc++.h>
using namespace std;

const int N = 16;

int n, m;
bool can[N][N];
unordered_map<string, int> id;
string names[N];

bool can_match(const vector<string>& ns) {
  for (int i = 0; i < ns.size(); i++) {
    for (int j = i + 1; j < ns.size(); j++) {
      if (!can[id[ns[i]]][id[ns[j]]]) {
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char** argv) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> names[i];
    id[names[i]] = i;
  }
  memset(can, true, sizeof(can));
  for (int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    can[id[a]][id[b]] = false;
    can[id[b]][id[a]] = false;
  }
  set<string> result;
  int mx_size = numeric_limits<int>::min();
  for (int mask = 0; mask < 1 << n; mask++) {
    vector<string> team;
    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i))) continue;
      team.push_back(names[i]);
    }
    if (can_match(team) && (int) team.size() > mx_size) {
      mx_size = team.size();
      result = set<string>(team.begin(), team.end());
    }
  }
  cout << result.size() << endl;
  for (string name : result) {
    cout << name << endl;
  }
  return 0;
}