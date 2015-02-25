#include <bits/stdc++.h>
using namespace std;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
  }

  template<class T>
  static inline std::vector<T> next_array(const int n) {
    std::vector<T> row(n);
    for (int i = 0; i < n; ++i)
      row[i] = io::next<T>();
    return row;
  }


  template<class T>
  static inline std::vector<std::vector<T>> next_table(const int n, const int m) {
    std::vector<std::vector<T>> table(n);
    for (int i = 0; i < n; ++i)
      table[i] = io::next_array<T>(m);
    return table;
  }
  
  template<class T>
  static void print(const T& t, const string& delimiter = " ") {
    std::stringstream sin;
    for (const auto& x : t) sin << x << delimiter;
    print_stream(sin, delimiter.size());
  }

private:
  static void print_stream(const std::stringstream& sin, const int ignore) {
    const std::string result = sin.str();
    std::cout << result.substr(0, result.size() - ignore) << std::endl;
  }
};

bool ok(const int expected_sum, const vector<vector<int>>& g) {
  bool okay = true;
  for (int i = 1; i < 3; ++i) {
    okay &= accumulate(g[i].begin(), g[i].end(), 0) == expected_sum;
  }
  int d1 = 0, d2 = 0;
  for (int i = 0; i < 3; ++i) {
    d1 += g[i][i];
    d2 += g[i][3 - i - 1];
  }
  okay &= d1 == expected_sum;
  okay &= d2 == expected_sum;
  for (int i = 0; i < 3; ++i) {
    int sum = 0;
    for (int j = 0; j < 3; ++j) {
      sum += g[j][i];
    }
    okay &= sum == expected_sum;
  }
  return okay && d1 && d2;
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  vector<vector<int>> g = io::next_table<int>(3, 3);
  for (int x = 1; x <= 100000; ++x) {
    const int a = x + g[0][1] + g[0][2];
    g[0][0] = x;
    g[1][1] = a - g[1][0] - g[1][2];
    g[2][2] = a - g[2][0] - g[2][1];

    if (g[1][1] <= 0 || g[2][2] <= 0 || g[1][1] > 100000 || g[2][2] > 100000) {
      continue;
    }
    if (ok(a, g)) break;
  }
  for (const auto& r : g) io::print(r);
  return 0;
}
