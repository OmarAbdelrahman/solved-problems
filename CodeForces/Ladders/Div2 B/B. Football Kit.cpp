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

struct team {
  int home;
  int away;

  team() { }

  team(int home, int away)
    : home(home), away(away) { }

  friend istream& operator >> (istream& sin, team& t) {
    sin >> t.home >> t.away;
    return sin;
  }

  friend ostream& operator << (ostream& sout, const team& t) {
    sout << t.home << " " << t.away;
    return sout;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  const int n = io::next<int>();
  vector<team> teams = io::next_array<team>(n);

  unordered_map<int, int> count;
  for (const team& t : teams) count[t.home]++;

  vector<team> result(n);
  for (int i = 0; i < n; ++i) {
    result[i].home = (n - 1) + count[teams[i].away];
    result[i].away = (2 * (n - 1)) - result[i].home;
  }

  io::print(result, "\n");
  return 0;
}
