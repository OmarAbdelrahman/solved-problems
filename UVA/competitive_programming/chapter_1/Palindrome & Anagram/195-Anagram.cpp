#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    auto f = [](const char& a, const char& b) {
        if (isupper(a) && islower(b)) {
            return tolower(a) <= b;
        }
        if (islower(a) && isupper(b)) {
            return a < tolower(b);
        }
        return a < b;
    };
    string s;
    while (n-- > 0) {
        cin >> s;
        sort(s.begin(), s.end(), f);
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end(), f));
    }
    return 0;
}