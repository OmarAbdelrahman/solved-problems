/*
ID: omar.se1
LANG: C++11
TASK: sort3
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

template<class T>
inline T next()
{
    T x;
    std::cin >> x;
    return x;
}

int get_count(int s1, int e1, int v, vector<int> a)
{
    int result = 0;
    for (int i = s1; i < e1; i++) {
        result += (int) (a[i] == v);
    }
    return result;
}

int main()
{
    // freopen("sort3.in", "r", stdin);
    // freopen("sort3.out", "w", stdout);
    vector<int> a(next<int>());
    vector<int> n(3, 0);
    for (int& it : a) {
        cin >> it;
        it -= 1;
        n[it] += 1;
    }
    for (int x : a) cerr << x << ' ';
    cerr << '\n';
    int s01 = get_count(0, n[0], 1, a);
    int s02 = get_count(0, n[0], 2, a);
    int s10 = get_count(n[0], n[0] + n[1], 0, a);
    int s12 = get_count(n[0], n[0] + n[1], 2, a);
    int s21 = get_count(n[0] + n[1], n[0] + n[1] + n[2], 1, a);
    int s20 = get_count(n[0] + n[1], n[0] + n[1] + n[2], 0, a);
    cerr << "zeros and ones " << s01 << ' ' << s10 << '\n';
    cerr << "zeros and twos " << s02 << ' ' << s20 << '\n';
    cerr << " ones and twos " << s12 << ' ' << s21 << '\n';
    int direct_swaps = min(s01, s10) + min(s12, s21) + min(s02, s20);
    int undirect_swaps = max(s01, s10);
    cout << direct_swaps + undirect_swaps << '\n';
}
