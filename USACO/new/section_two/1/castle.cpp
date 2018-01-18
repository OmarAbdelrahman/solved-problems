/*
ID: omar.se1
LANG: C++11
TASK: castle
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 55;

template<class T>
inline T next() {
  T x;
  std::cin >> x;
  return x;
}

struct node {
  bool up, down;
  bool left, right;
  int x, y;

  node() { }

  node(int _x, int _y, int n):
    x(_x), y(_y),
    up((n & 2) == 0),
    down((n & 8) == 0),
    left((n & 1) == 0),
    right((n & 4) == 0) { }

  void print() {
    cout << "(" << x << ", " << y << ") = " 
        << "(up = " << up << ", down = " << down 
        << ", left = " << left << ", right = " << right << ")\n";
  }
};

struct flood_fill {
  int components;
  int max_size;
  int n, m;

  vector<vector<bool>> visited;
  array<array<node, N>, N> grid;
  vector<vector<node>> connected;

  flood_fill(int _n, int _m) {
    components = 0;
    max_size = numeric_limits<int>::min();
    n = _n, m = _m;
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        grid[i][j] = node(i, j, next<int>());
      }
    }
  }

  int dfs(const node& cur) {
    const int x = cur.x;
    const int y = cur.y;
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (visited[x][y]) return 0;
    visited[x][y] = true;
    connected[components].push_back(cur);
    const node& value = grid[x][y];
    int count = 1;
    count += dfs(x - value.up, y);
    count += dfs(x + value.down, y);
    count += dfs(x, y - value.left);
    count += dfs(x, y + value.right);
    return count;
  }

  void do_it() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j]) {
          int count = dfs(grid[i][j]);
          max_size = max(max_size, count);
          components++;
        }
      }
    }
  }

  void print_components() {
    for (auto component : connected) {
      for (int i = 0; i < (int) component.size(); i++) {
        component[i].print();
      }
      cout << '\n';
    }
  }
};

int main() {
  //freopen("castle.in", "r", stdin);
  //freopen("castle.out", "w", stdout);
  int m, n;
  cin >> m >> n;
  flood_fill solver(n, m);
  solver.do_it();
  solver.print_components();
  cout << solver.components << '\n';
  cout << solver.max_size << '\n';
}
