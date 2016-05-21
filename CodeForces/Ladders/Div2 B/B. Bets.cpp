#include <bits/stdc++.h>
using namespace std;

struct athlete {
  int start_section;
  int end_section;
  int time;
  int cost;

  friend istream& operator >> (istream& sin, athlete& a) {
    sin >> a.start_section >> a.end_section >> a.time >> a.cost;
    return sin;
  }

  friend ostream& operator << (ostream& sout, athlete& a) {
    cout << a.start_section << " " << a.end_section << " " << a.time << " " << a.cost;
    return sout;
  }

  bool in_section(const int& x) const {
    return start_section <= x && x <= end_section;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n, m; cin >> n >> m;

  vector<athlete> athletes(m);
  for (athlete& a : athletes) {
    cin >> a;
  }

  int result = 0;
  for (int section = 1; section <= n; ++section) {
    int lowest_time = 1234;
    int index = -1;
    for (int i = 0; i < m; ++i) {
      const athlete& a = athletes[i];
      if (!a.in_section(section)) {
        continue;
      }
      if (a.time < lowest_time) {
        lowest_time = a.time;
        index = i;
      }
    }
    if (index == -1) {
      continue;
    }
    result += athletes[index].cost;
  }
  cout << result << endl;
  return 0;
}
