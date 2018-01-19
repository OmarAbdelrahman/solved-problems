/*
ID: omar.se1
LANG: C++11
TASK: castle
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

template<class T>
inline T next()
{
  T x;
  std::cin >> x;
  return x;
}

struct node
{
  bool up, down;
  bool left, right;
  int x, y;
  bool visited;
  int size;
  int component;

  node(): visited(false) { }

  node(int _x, int _y, int n):
    up((n & 2) == 0),
    down((n & 8) == 0),
    left((n & 1) == 0),
    right((n & 4) == 0),
    x(_x), y(_y),
    visited(false)
    {
    }

  vector<node*> dfs(vector<vector<node>>& grid)
  {
    if (visited) return {};
    visited = true;
    vector<node*> cur = {this};
    vector<pair<int, int>> adj = {{x - up, y}, {x + down, y}, {x, y - left}, {x, y + right}};
    for (const auto& p : adj) {
      vector<node*> next = grid[p.first][p.second].dfs(grid);
      cur.insert(end(cur), begin(next), end(next));
    }
    return cur;
  }

  void print() const
  {
    cerr << "(" << x << ", " << y << ") = " 
      << "(up = " << up << ", down = " << down 
      << ", left = " << left << ", right = " << right << ")\n";
  }
};

int main()
{
  //freopen("castle.in", "r", stdin);
  //freopen("castle.out", "w", stdout);
  int m, n;
  cin >> m >> n;
  vector<vector<node>> grid(n, vector<node>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      grid[i][j] = node(i, j, next<int>());
    }
  }
  int result = 0;
  int max_size = numeric_limits<int>::min();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      node& room = grid[i][j];
      if (!room.visited) {
        vector<node*> component = room.dfs(grid);
        for (node* cn : component) {
          cn->size = SIZE(component);
          cn->component = result;
        }
        max_size = max(max_size, SIZE(component));
        result++;
      }
    }
  }
  int x = -1, y = -1;
  int merge_size = numeric_limits<int>::min();
  char wall_direction = '-';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      
    }
  }
  cout << result << '\n';
  cout << max_size << '\n';
}
