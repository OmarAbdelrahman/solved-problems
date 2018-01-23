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

struct fraction
{
    int p, q;

    fraction(): p(0), q(1)
    {
    }

    fraction(int _p, int _q): p(_p), q(_q)
    {
        int g = __gcd(p, q);
        p /= g;
        q /= g;
        if (q < 0) {
            p = -p;
            q = -q;
        }
    }

    fraction(const fraction& other): p(other.p), q(other.q)
    {
    }

    fraction(fraction&& other): p(move(other.p)), q(move(other.q))
    {
    }

    bool operator < (const fraction& other) const
    {
        return p * other.q < other.p * q;
    }

    bool operator == (const fraction& other) const
    {
        return p * other.q == other.p * q;
    }

    friend ostream& operator << (ostream& ostr, const fraction& f)
    {
        ostr << f.p << '/' << f.q;
        return ostr;
    }
};

int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    auto m = next<int>();
    set<fraction> result;
    for (int d = 1; d <= m; d++) {
        for (int n = 0; n <= d; n++) {
            result.insert(fraction(n, d));
        }
    }
    for (auto&& f : result) cout << f << '\n';
}
