#include <bits/stdc++.h>
using namespace std;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
  }

  template<class T, typename Fun>
  static inline T next(Fun f) {
    T x; std::cin >> x;
    return f(x);
  }

  template<class T>
  static inline std::vector<T> next_array(const int n) {
    std::vector<T> row(n);
    for (int i = 0; i < n; ++i)
      row[i] = io::next<T>();
    return row;
  }

  template<class T, typename Fun>
  static inline std::vector<T> next_array(const int n, Fun f) {
    std::vector<T> row(n);
    for (int i = 0; i < n; ++i)
      row[i] = io::next<T>(f);
    return row;
  }

  template<class T>
  static inline std::vector<std::vector<T>> next_table(const int n, const int m) {
    std::vector<std::vector<T>> table(n);
    for (int i = 0; i < n; ++i)
      table[i] = next_array<T>(m);
    return table;
  }

  template<class T, typename Fun>
  static inline std::vector<std::vector<T>> next_table(const int n, const int m, Fun f) {
    std::vector<std::vector<T>> table(n);
    for (int i = 0; i < n; ++i)
      table[i] = next_array<T>(m, f);
    return table;
  }

  template<class T>
  static void print(const T& t, const string& delimiter = " ") {
    std::stringstream sin;
    for (const auto& x : t) sin << x << delimiter;
    print_stream(sin, delimiter.size());
  }

  template<class T>
  static inline void print_map(const T& m, const string& delimiter = " ") {
    std::stringstream sin;
    for (const auto& p : m) sin << "(" << p.first << ", " << p.second << ")" << delimiter;
    print_stream(sin, delimiter.size());
  }

private:
  static void print_stream(const std::stringstream& sin, const int ignore) {
    const std::string result = sin.str();
    std::cout << result.substr(0, result.size() - ignore) << std::endl;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  const int n = io::next<int>();
  const int m = io::next<int>();
  const vector<vector<int>> b = io::next_table<int>(n, m);

  vector<vector<int>> a(n, vector<int>(m, 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[i][j] == 0) {
        for (int k = 0; k < m; ++k) a[i][k] = 0;
        for (int k = 0; k < n; ++k) a[k][j] = 0;
      }
    }
  }

  vector<vector<int>> c(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int v = 0;
      for (int k = 0; k < m; ++k) v |= a[i][k];
      for (int k = 0; k < n; ++k) v |= a[k][j];
      c[i][j] = v;
    }
  }

  if (c == b) {
    cout << "YES" << endl;
    for (const auto& r : a) io::print(r);
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
