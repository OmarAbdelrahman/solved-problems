#include <bits/stdc++.h>
using namespace std;

class PublicTransit {
public:
  int f(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
  }

  int minimumLongestDistance(int R, int C) {
    int result = numeric_limits<int>::max();
    for (int a = 0; a < R; ++a) {
      for (int b = 0; b < C; ++b) {
        for (int c = 0; c < R; ++c) {
          for (int d = 0; d < C; ++d) {
            int biggest = numeric_limits<int>::min();
            for (int x1 = 0; x1 < R; ++x1) {
              for (int y1 = 0; y1 < C; ++y1) {
                for (int x2 = 0; x2 < R; ++x2) {
                  for (int y2 = 0; y2 < C; ++y2) {
                    int minDist = min({ f(x1, y1, x2, y2), f(x1, y1, a, b) + f(c, d, x2, y2), f(x1, y1, c, d) + f(a, b, x2, y2) });
                    biggest = max(biggest, minDist);
                  }
                }
              }
            }
            result = min(result, biggest);
          }
        }
      }
    }
    return result;
  }
};
