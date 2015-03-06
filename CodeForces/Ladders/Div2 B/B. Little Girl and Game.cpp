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

  const string s = io::next<string>();

  unordered_map<char, int> count; 
  for (const char ch : s) count[ch]++;

  int odd = 0;
  for (auto p : count) odd += (int) (p.second % 2 != 0);

  if (odd == 0 || odd % 2 != 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
