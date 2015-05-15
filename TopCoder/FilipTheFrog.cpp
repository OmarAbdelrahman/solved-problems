#include <bits/stdc++.h>
using namespace std;

class FilipTheFrog {
public:
	int countReachableIslands(vector<int> positions, int L) {
    const int n = positions.size();

    vector<bool> visited(n, false);
    visited[0] = true;

    queue<int> q;
    for (q.push(positions[0]); !q.empty(); q.pop()) {
      const int x = q.front();
      for (int i = 0; i < n; ++i) {
        if (!visited[i] && abs(x - positions[i]) <= L) {
          visited[i] = true;
          q.push(positions[i]);
        }
      }
    }

    int result = 0;
    for (bool value : visited) {
      if (value) {
        ++result;
      }
    }
    return result;
	}
};
