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

int change(int s1, int e1, int s2, int e2, int v1, int v2, vector<int>& a)
{
    int result = 0;
    for (int i = s1; i < e1; i++) {
        for (int j = s2; j < e2; j++) {
            if (a[i] == v1 && a[j] == v2) {
                swap(a[i], a[j]);
                result += 1;
                break;
            }
        }
    }
    return result;
}

int order_misfits(int s1, int e1, int s2, int e2, int v, vector<int>& a)
{
    int result = 0;
    for (int i = s1; i < e1; i++) {
        if (a[i] == v) {
            continue;
        }
        for (int j = s2; j < e2; j++) {
            if (a[j] == v) {
                swap(a[i], a[j]);
                result += 1;
                break;
            }
        }
    }
    return result;
}

int main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    vector<int> a(next<int>());
    vector<int> n(3, 0);
    for (int& it : a) {
        cin >> it;
        it -= 1;
        n[it] += 1;
    }
    int result = 0;
    result += change(0, n[0], n[0], n[0] + n[1], 1, 0, a);
    result += change(0, n[0], n[0] + n[1], n[0] + n[1] + n[2], 2, 0, a);
    result += change(n[0], n[0] + n[1], n[0] + n[1], n[0] + n[1] + n[2], 2, 1, a);
    result += order_misfits(0, n[0], n[0], n[0] + n[1] + n[2], 0, a);
    result += order_misfits(n[0], n[0] + n[1], n[0] + n[1], n[0] + n[1] + n[2], 1, a);
    cout << result << '\n';
}
