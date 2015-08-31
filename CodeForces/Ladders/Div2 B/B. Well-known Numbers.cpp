#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
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

  int s = io::next<int>();
  int k = io::next<int>();
  vector<int> numbers(100);
  numbers[0] = 1;
  int size;
  for (size = 1; numbers[size - 1] < s; ++size) {
    for (int i = size - 1; i >= 0 && i >= size - k; --i) {
      numbers[size] += numbers[i];
    }
  }
  vector<int> result;
  for (int i = size - 1; i >= 0; --i) {
    if (s >= numbers[i]) {
      result.push_back(numbers[i]);
      s -= numbers[i];
    }
  }
  result.push_back(0);
  cout << result.size() << endl;
  io::print(result, " ");
  return 0;
}