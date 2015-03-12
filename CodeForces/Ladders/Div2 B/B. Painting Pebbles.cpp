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

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int p = io::next<int>();
  int c = io::next<int>();
  vector<int> ls = io::next_array<int>(p);

  int m = *min_element(ls.begin(), ls.end());
  vector<vector<int>> result(p);
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < m; ++j) {
      result[i].push_back(1);
    }
    if (ls[i] - m > c) {
      cout << "NO" << endl;
      return 0;
    }
    int rem = ls[i] - m - 1;
    for (int j = 1; rem-- >= 0; ++j) {
      result[i].push_back(j);
    }
  }
  
  cout << "YES" << endl;
  for (auto& row : result) io::print(row);
  return 0;
}
