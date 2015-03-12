#include <bits/stdc++.h>
using namespace std;

struct io {
  template<class T>
  static inline T next() {
    T x; std::cin >> x;
    return x;
  }
};

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);

  int n = io::next<int>();

  deque<long long> values[2];
  vector<long long> sum(2, 0);
  int last;

  for (int i = 0; i < n; ++i) {
    long long x = io::next<long long>();
    last = (int) (x < 0);
    values[last].push_back(abs(x));
    sum[last] += abs(x);
  }

  values[0].push_front(sum[0]);
  values[1].push_front(sum[1]);

  if (values[0] == values[1]) {
    values[last].push_back(1);
  }
  cout << (values[0] > values[1] ? "first" : "second") << endl;
  return 0;
}
