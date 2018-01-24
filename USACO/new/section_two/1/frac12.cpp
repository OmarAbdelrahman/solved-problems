/*
ID: omar.se1
LANG: C++11
TASK: frac1
*/

#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next()
{
    T x;
    std::cin >> x;
    return x;
}

void print(int a, int b)
{
    cout << a << '/' << b << '\n';
}

void solve(int n1, int d1, int n2, int d2, int m)
{
    if (d1 + d2 > m) return;
    solve(n1, d1, n1 + n2, d1 + d2, m);
    print(n1 + n2, d1 + d2);
    solve(n1 + n2, d1 + d2, n2, d2, m);
}

int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    auto m = next<int>();
    print(0, 1);
    solve(0, 1, 1, 1, m);
    print(1, 1);
}
