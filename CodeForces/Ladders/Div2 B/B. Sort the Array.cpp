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

  static inline void read_file(const char* s) {
#ifndef ONLINE_JUDGE
    std::freopen(s, "r", stdin);
#endif
  }

  static inline void write_file(const char* s) {
    std::freopen(s, "w", stdout);
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

  static inline std::string next_line(const bool ignore = true) {
    if (ignore) std::cin.ignore();
    std::string s; std::getline(std::cin, s);
    return s;
  }

  static inline std::vector<std::string> next_lines(const int n) {
    std::vector<std::string> row(n);
    for (int i = 0; i < n; ++i)
      std::getline(std::cin, row[i]);
    return row;
  }

  static inline std::vector<std::string> next_lines(const std::string& delimiter) {
    std::vector<std::string> row;
    for (std::string value; std::getline(std::cin, value) && value != delimiter; row.push_back(value));
    return row;
  }

  template<class T>
  static inline std::vector<T> next_array_delimiter(const T& delimiter) {
    std::vector<T> row;
    for (T value; std::cin >> value && value != delimiter; row.push_back(value));
    return row;
  }

  template<class T>
  static inline void print_array(T a[], const int size, const string& delimiter = " ") {
    std::stringstream sin;
    for (int i = 0; i < size; ++i) sin << a[i] << delimiter;
    print_stream(sin, delimiter.size());
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
  const int n = io::next<int>();
  vector<int> a = io::next_array<int>(n);
  vector<int> b = a;
  sort(b.begin(), b.end());

  unordered_map<int, int> m;
  for (int i = 0; i < n; ++i) {
    m[b[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = m[a[i]];
  }

  int L = -1, R = -1;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] != i) {
      L = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] != i) {
      R = i;
    }
  }
  if (R == -1 || L == -1) {
    cout << "yes" << endl;
    cout << "1 1" << endl;
  } else {
    reverse(a.begin() + L, a.begin() + R + 1);
    for (int i = 0; i < n; ++i) {
      if (a[i] != i) {
        cout << "no" << endl;
        return 0;
      }
    }
    cout << "yes" << endl;
    cout << L + 1 << " " << R + 1 << endl;
  }
  return 0;
}
